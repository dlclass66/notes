//输入格式 第一行为字符串word1 第二行为字符串word2
//初始化是一个字符串没有 一个有 编辑距离就是把有内容的字符串全部删除
//注意插入 删除 替换的对应的递推条件 
//min使用{}可能会报错



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
            vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
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