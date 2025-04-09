mod hash_struct;
use hash_struct::{Pair, HashStruct};

fn main() {
    let p1 = Pair{key: "hello".to_string(), value: 1};
    let p2 = Pair{key: "world".to_string(), value: 1};
    let p3 = Pair{key: "world".to_string(), value: 2};

    println!("p1 == p2: {}", p1 == p2);
    println!("p2 == p3: {}", p2 == p3);
}
