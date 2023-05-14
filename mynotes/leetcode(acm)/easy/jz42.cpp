//使用动态规划是最容易理解的 dp[i]表示以下标i - 1的数字结尾的连续最大和


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        vector<int>dp(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            dp[i] = max(nums[i - 1], nums[i - 1] + dp[i - 1]);
            ans = max(dp[i], ans);
        }
        return ans;
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().maxSubArray(nums);
    cout << ans;
    while (1);
}