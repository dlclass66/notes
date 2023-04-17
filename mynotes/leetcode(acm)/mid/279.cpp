//完全背包 求最小 要注意未初始化的数组
//可以不先生成完全平方数组


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<int> nums(100, 0);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = pow(i + 1, 2);
        }
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= n; j++) {
                if (dp[j] == -1 || dp[j - nums[i]] == -1) {
                    if (dp[j - nums[i]] >= 0) {
                        dp[j] = dp[j - nums[i]] + 1;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    dp[j] = min(dp[j], dp[j - nums[i]] + 1);
                }
            }
        }
        return dp[n];
    }
};
int main() {
    int target = 0;
    cin >> target;
    int ans = Solution().numSquares(target);
    cout << ans << endl;
    while (1);
}