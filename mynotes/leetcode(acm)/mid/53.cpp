//输入格式 第一行为数组 数字间用空格隔开
//动态规划 一维数组即可 因为连续 dp[i]代表以i结尾的最大连续子串和 根据前一个最大和大于0还是小于0分条件递推 



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (dp[i - 1] < 0) {
                dp[i] = nums[i];
            }
            else {
                dp[i] = nums[i] + dp[i - 1];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> nums1;
    while (cin >> num) {
        nums1.push_back(num);
    }
    int ans = Solution().maxSubArray(nums1);
    cout << ans << endl;
    while (1);
}