//输入为数组 数字间用空格隔开
//01背包  重量和价值都是nums的值 判断能否在重量限制为 sum / 2 的情况下 使价值也为sum / 2 找到即返回真
//可以用一维数组实现 因为只有上一行会被使用

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int nums_size = nums.size();
        vector<vector<int>> dp(nums_size, vector<int>(sum / 2 + 1, 0));
        for (int i = 0; i < sum / 2 + 1; i++) {
            if (nums[0] <= i) {
                dp[0][i] = nums[0];
            }
        }
        for (int i = 1; i < nums_size; i++) {
            for (int j = 0; j < sum / 2 + 1; j++) {
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
            if (dp[i][sum / 2] == sum / 2) {
                return true;
            }
        }
        return false;
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    bool ans = Solution().canPartition(nums);
    cout << ans << endl;
    while (1);
}