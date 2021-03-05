fn main() {
    let ref_to_i32 = dangle();
}
fn dangle() -> &i32 {
    let i:i32 = 22;
    &i
}
