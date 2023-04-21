//输入格式 第一行为第一个字符串 第二行为第二个字符串
//利用动态规划求出最长公共子串即可


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
            vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size()][word2.size()];
    }
};
int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    int ans = Solution().minDistance(s, t);
    cout << ans << endl;
    while (1);
}