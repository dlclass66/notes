//输入格式 第一行为数组 数字间用空格隔开 第二行为fee
//动态规划 每天有两种状态 持有股票 不持有股票 卖出股票时扣除手续费

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int p_size = prices.size();
        vector<vector<int>> dp(p_size, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < p_size; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[p_size - 1][1];
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int fee = 0;
    cin >> fee;
    int ans = Solution().maxProfit(nums, fee);
    cout << ans << endl;
    while (1);
}