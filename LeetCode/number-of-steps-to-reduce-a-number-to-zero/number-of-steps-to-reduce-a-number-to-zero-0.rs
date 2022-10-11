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

fn solution(mut num: i32) -> i32 {
    let mut count = 0;

    while num > 0 {
        if num % 2 == 0 {
            num /= 2;
        } else {
            num -= 1;
        }

        count += 1;
    }

    count
}
