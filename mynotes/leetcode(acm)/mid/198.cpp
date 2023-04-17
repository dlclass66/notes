//输入格式为一行数组 数字间用空格隔开
//动态规划 dp数组含义为直到下标为i的房子 最大金额 递推的条件就是偷或者不偷当前房子 注意dp[0], dp[1]要初始化


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().rob(nums);
    cout << ans << endl;
    while (1);
}