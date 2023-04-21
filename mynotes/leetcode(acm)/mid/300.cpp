//输入格式 第一行为数组 数字间用空格隔开
//动态规划 dp[i] 表示以下标为i的数字结尾子数组的最大长度 注意确定dp[i]需要有内层循环 遍历前面的才能确定
//开始准备使用单调栈 但是并不一定以（最近的）（小于当前数字的）数字结尾的能和当前数字构成最长的子数组


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
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
    int ans = Solution().lengthOfLIS(nums);
    cout << ans << endl;
    while (1);
}