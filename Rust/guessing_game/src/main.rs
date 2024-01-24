use std::io; // prelude

fn main() {
    println!("Guess Number!");

    println!("Guess a number ...!");

    // let foo = 1; // default as immutable
    // let bar = foo;

    let mut guess: String = String::new();

    io::stdin().read_line(&mut  guess).expect("cannot read!");

    println!("what you guess is {}", guess);
}