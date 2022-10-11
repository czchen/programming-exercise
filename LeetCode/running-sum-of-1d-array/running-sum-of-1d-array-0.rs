fn main() {
    let nums: Vec<i32> = std::env::args()
        .collect::<Vec<String>>()
        .drain(1..)
        .map(|x| x.parse().unwrap())
        .collect::<Vec<i32>>();

    let ans = solution(nums);

    println!("{:?}", ans)
}

fn solution(mut nums: Vec<i32>) -> Vec<i32> {
    let mut sum = 0;
    for x in nums.iter_mut() {
        sum += *x;
        *x = sum;
    }
    nums
}
