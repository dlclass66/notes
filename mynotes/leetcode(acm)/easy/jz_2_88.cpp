//动态规划 



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp.back();
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().minCostClimbingStairs(nums);
    cout << ans;
    while (1);
}