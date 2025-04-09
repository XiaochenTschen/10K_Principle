use std::cmp::Ordering;
use std::fmt;

#[derive (Debug)]
pub struct Pair {
    pub key: String,
    pub value: u32,
}

pub struct HashStruct{
    map: Vec<Pair>,
}

impl fmt::Display for Pair {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "{} | {}", self.key, self.value)
    }
}

impl PartialEq for Pair {
    fn eq (&self, rhs: &Self) -> bool {
        self.key == rhs.key
    }
}

impl PartialOrd for Pair {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        if self.value != other.value {
            Some(self.value.cmp(&other.value))
        }
        else {
            Some(self.key.cmp(&other.key))
        }
    }
}

// new, insert, sort
impl HashStruct {
    pub fn new() -> Self {
        HashStruct{
            map: Vec::<Pair>::new()
        }
    }

    pub fn insert(&mut self, new_key: String) {
        for pair in &mut self.map {
            if pair.key == new_key {
                pair.value += 1;
                return;
            }
        }
        self.map.push( Pair {key: new_key, value: 1});
    }

    pub fn sort(&mut self) {
        self.map.sort_by(|a, b| a.partial_cmp(b).unwrap());
    }
}