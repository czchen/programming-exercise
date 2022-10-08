fn main() {
    let args: Vec<String> = std::env::args().collect();
    let mut nums: Vec<i32> = Vec::new();

    for i in 1..args.len() {
        nums.push(args[i].parse().unwrap());
    }

    println!("{0}", solution(nums));
}

fn solution(nums: Vec<i32>) -> i32 {
    let mut hash: std::collections::HashMap<_, _> = std::collections::HashMap::new();

    for &x in nums.iter() {
        hash.insert(x, ());
    }

    let mut ans = 0;

    for &x in nums.iter() {
        if !hash.contains_key(&(x - 1)) {
            let mut current = x;

            while hash.contains_key(&current) {
                current += 1;
            }

            ans = std::cmp::max(ans, current - x);
        }
    }

    return ans;
}
