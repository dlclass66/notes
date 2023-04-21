//输入格式 第一行为数组 数字间用空格隔开
//使用动态规划 dp数组需要2维 因为每天对应4种情况 
//0 第一次不持有股票（卖出了第一次持有的） 1 第一次持有股票
//2 第二次不持有股票（卖出了第二次持有的） 3 第二次持有股票
//注意初始化dp[0][1] 和 dp[0][3]
//还有一种情况是还没有买入第一支股票 但是这种情况现金永远是0 不需要考虑
//最开始的想法是得到所有连续上升区间 找到最大的2个 但是可能不连续的区间也符合题意



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
            dp[i][2] = max(dp[i - 1][3] + prices[i], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][0] - prices[i]);
        }
        return max(dp[prices.size() - 1][0], dp[prices.size() - 1][2]);
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