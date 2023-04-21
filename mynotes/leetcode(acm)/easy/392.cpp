//输入格式 第一行为第一个字符串 第二行为第二个字符串
//动态规划 就是求s t的最长公共连续子串的长度是不是等于s的长度
//递推时因为此题判断s 是不是t的子串 所以只有t可以删元素 s不用回退（优化）


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, 0));
        if (s.size() == 0) {
            return true;
        }
        for (int i = 1; i <= t.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (t[i - 1] == s[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                if (j == s.size() && dp[i][j] == s.size()) {
                    return true;
                }
            }
        }
        return false;
    }
};
int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    bool ans = Solution().isSubsequence(s, t);
    cout << ans << endl;
    while (1);
}