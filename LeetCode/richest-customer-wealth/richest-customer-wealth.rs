fn main() {}

pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
    let mut res = 0;

    for account in accounts.iter() {
        let sum = account.iter().fold(0, |mut sum, &x| {
            sum += x;
            sum
        });

        res = std::cmp::max(sum, res);
    }

    return res;
}
