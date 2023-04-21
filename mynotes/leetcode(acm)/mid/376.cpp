//输入格式 第一行为数组 数字间用空格隔开
//使用动态规划 二维dp数组 dp[i][0]表示以下标为i的数结尾的且i是山谷的最长摆动数列长度 dp[i][1]表示i是山峰 注意初始化
//可以使用贪心 时间复杂度更好 但是需要处理的情况更多



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        int ans = 1;
        dp[0][0] = 1;
        dp[0][1] = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] < nums[j]) {
                    dp[i][0] = max(dp[i][0], dp[j][1] + 1);
                }
                else if (nums[i] > nums[j]) {
                    dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                }
                else {
                    continue;
                }
            }
            ans = max(dp[i][0], max(dp[i][1], ans));
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
    int ans = Solution().wiggleMaxLength(nums);
    cout << ans << endl;
    while (1);
}