//输入格式 第一行为数组 数字间用空格隔开
//动态规划 每天分为4个条件 
//0 今天持有 1 今天卖出 2 今天是冷静期 3 今天不是冷静期（未持有）



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][2] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = dp[i - 1][1];
            dp[i][3] = max(dp[i - 1][2], dp[i - 1][3]);
        }
        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().maxProfit(nums);
    cout << ans << endl;
    while (1);
}