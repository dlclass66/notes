//输入格式 数组 数字间用空格隔开
//动态规划 需要使用一个二维数组 dp[i][0]表示以i结尾的最长递增子序列的长度 dp[i][1]表示子序列的个数
//通过遍历确定倒数第二个数 递推 注意如果和最大长度相等则加而不是取最大值



#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        int ans = 0;
        int maxs = 1;
        for (int i = 0; i < nums.size(); i++) {
            int maxsize = 1;
            int maxcount = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j][0] + 1 == maxsize) {
                        maxcount += dp[j][1];
                    }
                    else if (dp[j][0] + 1 > maxsize) {
                        maxsize = dp[j][0] + 1;
                        maxcount = dp[j][1];
                    }
                }
            }
            dp[i][0] = maxsize;
            dp[i][1] = maxcount;
            if (dp[i][0] == maxs) {
                ans += dp[i][1];
            }
            else if (dp[i][0] > maxs) {
                ans = dp[i][1];
                maxs = dp[i][0];
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
    int ans = Solution().findNumberOfLIS(nums);
    cout << ans;
    while (1);
}