use std::{i128, mem::size_of_val};

fn variables() {
    println!("Hello, world!");

    let someFloat: f64 = 1.0;
    let logical: bool = true;

    let someInt: i32 = 2;

    // someInt = someFloat;

    println!("ans = {someInt} ");

    let foo: i128 = 123;
    let bar: f64 = 44.0;

    println!("foo = {foo}, bar = {bar}");

    // foo = 7; cannot change the value! so it's like the kotlin val
    println!("foo = {foo}");

    let mut variable: i32 = 123;
    println!("variable = {variable}");
    variable = 456;
    println!("variable = {variable}");
}

fn analyze_slices(slice: &[i32]) {
    println!("first element of the slice: {}", slice[0]);
    println!("the slice has {} elements", slice.len());
}

fn arrays_and_slices() {
    // fixed sized array
    let xs: [i32; 5] = [1, 2, 3, 4, 5];

    // all elements of the array can be initialized to some value
    let ys: [i32; 100] = [0; 100];

    // 0 based indexing...
    println!("xs[0] = {}", xs[0]);

    println!("size of xs = {}", xs.len());

    // arrays are stack allocated
    println!("The array xs occupies {}", size_of_val(&xs));

    // arrays can be passed as slices
    analyze_slices(&xs);

    println!("borrow a section of the array as a slice");

    // ys[0] = 0;
    // ys[1] = 1;
    // ys[2] = 2;
    // ys[3] = 3;
    // ys[4] = 4;
    // ys[5] = 5;
    analyze_slices(&ys[1..4]);

    // example of an empty array
    let empty_array: [i32; 0] = [];


    assert_eq!(&empty_array, &[]);
    println!("--- --- ---");
    assert_eq!(&empty_array, &[][..]); // same, but more veroboseindex


    for i in 0 .. xs.len() {
        println!("{} = {}", i, xs[i] );
    }

}

fn main() {
    // arraysAndSlices();
    arrays_and_slices();
}
