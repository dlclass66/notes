//输入格式 第一行为amount 第二行为数组 数字间用空格隔开
//完全背包 因为每枚硬币可以无限使用 因为是求方法数 所以是累加 dp[0] 要初始化 因为是完全背包 所以从前往后遍历 



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};
int main() {
    int amount = 0;
    cin >> amount;
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().change(amount, nums);
    cout << ans << endl;
    while (1);
}