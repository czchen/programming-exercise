class Solution {
public:
    int get_gcd(int x, int y) {
        int z = y % x;

        if (z == 0) {
            return x;
        }
        return get_gcd(z, x);
    }

    void rotate(vector<int>& nums, int k) {
        if (k == 0) return;

        int pos = 0;
        int tmp = nums[pos];

        int gcd = get_gcd(k, nums.size());
        int loop = nums.size() / gcd;

        for (int i = 0; i < gcd; ++i) {
            int pos = i;
            int tmp = nums[pos];

            for (int j = 0; j < loop; ++j) {
                int new_pos = (pos + k) % nums.size();
                int new_tmp = nums[new_pos];

                nums[new_pos] = tmp;

                pos = new_pos;
                tmp = new_tmp;
            }
        }
    }
};
