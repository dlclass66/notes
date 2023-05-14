// 使用动态规划 dp[i][j] 表示s前i个字符与p前j个字符是否匹配




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*') {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        //分别表示匹配0个 1个 2个及以上的情况 
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] || dp[i - 1][j];
                    }
                    else {
                        //匹配0个
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};



int main() {
    string s;
    cin >> s;
    string p;
    cin >> p;
    bool ans = Solution().isMatch(s, p);
    cout << ans;
    while (1);
}