use std::{
    collections::HashMap,
    env,
    fs::File,
    io::{self, Read},
    thread,
};

#[derive(Debug)]
enum Error {
    InvaliadNumberOfArgs,
    InvaliadFile,
    FileNotReadable,
}

fn main() -> Result<(), Error> {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        return Err(Error::InvaliadNumberOfArgs);
    }

    let mut handles = Vec::new();

    for file_path in &args[1..] {
        let path = file_path.clone();

        let handle = thread::spawn(move || {
            match read_and_count(&path) {
                Ok(result) => {
                    println!("File: {}", path);
                    for (word, count) in result {
                        println!("{}: {}", word, count);
                    }
                }
                Err(e) => eprintln!("Error reading {}: {:?}", path, e),
            }
        });

        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap(); // join 等待子线程完成
    }

    Ok(())
}

fn read_and_count(file_path: &str) -> Result<Vec<(String, usize)>, Error> {
    let mut file = File::open(file_path).map_err(|_| Error::InvaliadFile)?;

    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .map_err(|_| Error::FileNotReadable)?;

    let words = contents.split_whitespace();

    let mut occurrences_hash: HashMap<String, usize> = HashMap::new();
    for word in words {
        let word = word.to_lowercase().replace([';', ':', '.', ',', '\n'], "");
        *occurrences_hash.entry(word).or_insert(0) += 1;
    }

    let mut occurrences_vec: Vec<(String, usize)> = occurrences_hash.into_iter().collect();

    occurrences_vec.sort_by(|a, b| b.1.cmp(&a.1).then_with(|| a.0.cmp(&b.0)));

    Ok(occurrences_vec)
}
