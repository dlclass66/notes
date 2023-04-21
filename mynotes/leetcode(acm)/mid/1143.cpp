//输入格式 第一行为字符串text1 第二行为字符串text2
//动态规划 这里的子字符串可以不连续 有两个字符串 所以采用二维dp数组 为了避免初始化 下标要处理 
//因为不需要连续 所以数组的含义不是以i， j结尾的子串 而是前i，j个串中的最长子串 
//如果是以i j 结尾 循环太多 会超时


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
int main() {
    string text1;
    cin >> text1;
    string text2;
    cin >> text2;
    int ans = Solution().longestCommonSubsequence(text1, text2);
    cout << ans << endl;
    while (1);
}