fn main() {
    let args: Vec<String> = std::env::args().collect();
    let mut nums = Vec::new();

    for i in 1..args.len() {
        nums.push(args[i].parse::<i32>().unwrap());
    }

    println!("{0}", solution(nums));
}

fn solution(mut nums: Vec<i32>) -> i32 {
    nums.sort();

    let mut ans = 0;
    let mut size = 0;
    let mut previous = std::i32::MIN;

    for &num in nums.iter() {
        if num == previous + 1 {
            size += 1
        } else if num == previous {
        } else {
            ans = std::cmp::max(ans, size);
            size = 1;
        }

        previous = num;
    }
    ans = std::cmp::max(ans, size);

    return ans;
}
