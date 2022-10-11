fn main() {
    let x: i32 = std::env::args()
        .collect::<Vec<String>>()
        .drain(1..)
        .collect::<Vec<String>>()[0]
        .parse()
        .unwrap();

    let ans = solution(x);

    println!("{:?}", ans);
}

fn solution(n: i32) -> Vec<String> {
    let mut ans: Vec<String> = Vec::with_capacity(n as usize);

    for x in 1..(n + 1) {
        if x % 15 == 0 {
            ans.push("FizzBuzz".to_string());
        } else if x % 3 == 0 {
            ans.push("Fizz".to_string());
        } else if x % 5 == 0 {
            ans.push("Buzz".to_string());
        } else {
            ans.push(x.to_string());
        }
    }

    return ans;
}
