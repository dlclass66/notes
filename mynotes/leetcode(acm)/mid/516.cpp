//动态规划 使用二维数组表示区间i j （闭区间）的最长回文串长度  
//根据递推公式确定遍历顺序 注意ij距离小于等于1的情况



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[j] == s[i]) {
                    if (j - i <= 1) {
                        dp[i][j] = j - i + 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
int main() {
    string s;
    cin >> s;
    int ans = Solution().longestPalindromeSubseq(s);
    cout << ans << endl;
    while (1);
}