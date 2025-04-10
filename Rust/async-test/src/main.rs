use std::{collections::HashMap, env};
use tokio::{fs::File, io::AsyncReadExt};

#[derive(Debug)]
enum Error {
    InvaliadNumberOfArgs,
    InvaliadFile,
    FileNotReadable,
}

#[tokio::main]
async fn main() -> Result<(), Error> {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        return Err(Error::InvaliadNumberOfArgs);
    }

    let mut handles = Vec::new();

    for file_path in &args[1..] {
        let path = file_path.clone();
        // 为每个文件启动一个异步任务
        let handle = tokio::spawn(async move {
            match read_and_count(&path).await {
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

    // 等待所有任务完成
    for handle in handles {
        handle.await.unwrap(); // unwrap 是因为 tokio::spawn 返回的是 Result<_, JoinError>
    }

    Ok(())
}

async fn read_and_count(file_path: &str) -> Result<Vec<(String, usize)>, Error> {
    let mut file = File::open(file_path)
        .await
        .map_err(|_| Error::InvaliadFile)?;

    let mut contents = String::new();
    file.read_to_string(&mut contents)
        .await
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
