//开始尝试暴力回溯算法 超时 改用动态规划
//动态规划思路：dp[i][j]表示i个骰子和为j的次数
//多一个骰子 只需要考虑多的骰子即可 注意初始化 1个骰子和为1-6的次数都为1
//最后再计算概率即可



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                for (int k = i - 1; k <= 6 * (i - 1); k++) {
                    if (k == 0) {
                        dp[1][j] = 1;
                    }
                    else {
                        dp[i][j + k] += dp[i - 1][k];
                    }
                }
            }
        }
        double s = pow(1.0 / 6, n);
        vector<double> ans(dp[n].begin() + n, dp[n].end());
        for (int i = 0; i < ans.size(); i++) {
            ans[i] *= s;
        }
        return ans;
    }
};

int main() {
    int num = 0;
    cin >> num;
    vector<double> ans = Solution().dicesProbability(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}