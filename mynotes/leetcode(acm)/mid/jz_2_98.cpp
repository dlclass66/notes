//动态规划 使用一个一维dp数组即可




#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>dp(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};
int main() {
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    int ans = Solution().uniquePaths(m, n);
    cout << ans;
    while (1);
}