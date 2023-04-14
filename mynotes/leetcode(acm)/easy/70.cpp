//输入数字n
//动态规划 使用数组递推


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().climbStairs(num);
    cout << ans << endl;
    while (1);
}