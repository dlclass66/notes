//动态规划 dp[i]表示长度为i的最长可得到的乘积 如果i小于n 则需要考虑只有一段的情况  




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 0; i <= n; i++) {
            if (i < n) {
                dp[i] = i;
            }
            for (int j = 1; j <= i / 2; j++) {
                dp[i] = max(dp[j] * dp[i - j], dp[i]);
            }
        }
        return dp[n];
    }
};


int main() {
    int n = 0;
    cin >> n;
    int ans = Solution().cuttingRope(n);
    cout << ans;
    while (1);
}