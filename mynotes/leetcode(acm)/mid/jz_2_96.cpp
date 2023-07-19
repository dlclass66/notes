//使用动态规划 dp[i][j]表示s1的前i个字符和s2的前j个字符能否交错组成s3的前i+j个字符
//dp[0][0] 初始化为true
//先比较s1和s2的长度和是否和s3的长度相等




#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        vector<vector<bool>> dp(s1.size() + 1,
            vector<bool>(s2.size() + 1));
        dp[0][0] = true;
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                else if (i == 0) {
                    if (s2[j - 1] == s3[j - 1]) {
                        dp[0][j] = dp[0][j - 1];
                    }
                }
                else if (j == 0) {
                    if (s1[i - 1] == s3[i - 1]) {
                        dp[i][0] = dp[i - 1][0];
                    }
                }
                else {
                    if (s2[j - 1] == s3[i + j - 1]) {
                        dp[i][j] = dp[i][j - 1];
                    }
                    if (!dp[i][j] && s1[i - 1] == s3[i + j - 1]) {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
    bool ans = Solution().isInterleave(s1, s2, s3);
    cout << ans;
    while (1);
}
