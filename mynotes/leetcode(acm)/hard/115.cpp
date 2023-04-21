//输入格式 第一行为字符串 s 第二行为字符串t
//动态规划 有两个字符串 所以使用二维dp数组 dp[i][j] 表示以s前i个字符组成的字符串的子串和以t前j个字符组成的字符串的匹配个数 注意初始化
//只有s能删除 t不能删除 所以每次t不用回退 



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<unsigned int>> dp(s.size() + 1,
            vector<unsigned int>(t.size() + 1, 0));
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};
int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int ans = Solution().numDistinct(s, t);
    cout << ans << endl;
    while (1);
}