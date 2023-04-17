//输入格式 第一行数组 中间用空格隔开 第二行amount
//多重背包 此dp数组的含义是最少的硬币数 注意此时要特别标记还未初始化的数组 然后dp[0] 为0 这样才能成功递推



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j] < 0 || dp[j - coins[i]] < 0) {
                    if (dp[j - coins[i]] >= 0) {
                        dp[j] = dp[j - coins[i]] + 1;
                    }
                    else {
                        continue;
                    }
                }
                else {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
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
    unsigned int ans = Solution().coinChange(nums, target);
    cout << ans << endl;
    while (1);
}