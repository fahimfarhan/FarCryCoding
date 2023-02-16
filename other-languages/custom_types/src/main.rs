use core::fmt;

struct Person {
    name: String,
    age: i32,
}

impl fmt::Display for Person {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "({}, {})", self.name, self.age)
    }
}

struct Unit {}

struct Point {
    x: i32,
    y: i32,
}

struct Rectangle {
    top_left: Point,
    bottom_right: Point,
}

fn main() {
    println!("Custom types tutorial!");

    let name = String::from("Peter");
    let age: i32 = 25;

    let peter_griffin = Person { name, age };

    println!("{} is a person!", peter_griffin);
}
