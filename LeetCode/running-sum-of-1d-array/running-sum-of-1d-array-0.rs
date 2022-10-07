fn main() {
    let args: Vec<String> = std::env::args().collect();
    let mut nums = Vec::new();

    for i in 1..args.len() {
        nums.push(args[i].parse::<i32>().unwrap());
    }

    let ans = solution(nums);

    for x in ans.iter() {
        print!("{} ", x)
    }
}

fn solution(nums: Vec<i32>) -> Vec<i32> {
    let mut ans = Vec::new();

    let mut sum = 0;
    for x in nums.iter() {
        sum += *x;
        ans.push(sum);
    }

    return ans;
}
