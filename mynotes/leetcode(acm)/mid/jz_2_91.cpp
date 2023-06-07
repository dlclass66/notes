//采用动态规划 dp[i][j]表示第i - 1个房子刷第j种颜色的最小花费



#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size() + 1, vector<int>(3, 0));
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i - 1][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i - 1][2];
        }
        return min(dp.back()[0], min(dp.back()[1], dp.back()[2]));
    }
};

int main() {
    int num = 0;
    vector<int> nums(3, 0);
    vector<vector<int>> costs;
    int i = 0;
    while (cin >> num) {
		nums[i] = num;
        i++;
        if (i == 3) {
            i = 0;
            costs.push_back(nums);
        }
	}
    int ans = Solution().minCost(costs);
    cout << ans;
    while (1);
}