//使用动态规划 dp[i]表示凑成总金额为i所需的最少的硬币个数 有点像背包 coin的种类一个一个加
//注意无法凑成的情况 把dp[i]初始化为amount+1识别 dp[0]=0 



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if (dp[amount] >= amount + 1) {
            dp[amount] = -1;
        }
        return dp[amount];
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
    int target = 0;
    cin >> target;
    int ans = Solution().coinChange(nums, target);
    cout << ans;
    while (1);
}