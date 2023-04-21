//输入格式 第一行为数字k 第二行为数组 数字间用空格隔开
//动态规划 使用二维数组 每个位置有2k种状态 注意初始化和递推即可



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, 0));
        for (int i = 0; i < k; i++) {
            dp[0][2 * i + 1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < k; j++) {
                dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j + 1] + prices[i]);
                if (j == 0) {
                    dp[i][1] = max(dp[i - 1][1], -prices[i]);
                }
                else {
                    dp[i][2 * j + 1] = max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j - 2] - prices[i]);
                }
            }
        }
        return dp[prices.size() - 1][2 * k - 2];
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    int k = 0;
    cin >> k;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().maxProfit(k, nums);
    cout << ans << endl;
    while (1);
}