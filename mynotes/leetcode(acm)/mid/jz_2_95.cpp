//采用动态规划 dp[i][j]表示text1前i个和text2前j个的最长公共子序列



#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    string text1;
    cin >> text1;
    string text2;
    cin >> text2;
    int ans = Solution().longestCommonSubsequence(text1, text2);
    cout << ans;
    while (1);
}