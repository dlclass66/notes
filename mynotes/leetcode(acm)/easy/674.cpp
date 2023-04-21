//输入格式 第一行为数组 数字间用空格隔开
//动态规划 这次无需内循环 因为只有连续子数组才符合条件



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
                ans = max(ans, dp[i]);
            }
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
    int ans = Solution().findLengthOfLCIS(nums);
    cout << ans << endl;
    while (1);
}