//输入格式 第一行为字符串s 第二行为字符串数组 字符串间用空格隔开
//完全背包 dp数组是bool数组 注意dp[0] 要初始化为true 字符串string比较直接使用=即可 因为有重载运算符 因为单词可能在后面再出现 所以单词循环要放在内层


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int j = 0; j <= s.size(); j++) {
            for (int i = 0; i < wordDict.size(); i++) {
                if (j < wordDict[i].size()) {
                    continue;
                }
                dp[j] = dp[j] || (dp[j - wordDict[i].size()] &&
                    s.substr(j - wordDict[i].size(),
                        wordDict[i].size()) == wordDict[i]);
            }
        }
        return dp[s.size()];
    }

};
int main() {
    string s;
    cin >> s;
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
    }
    bool ans = Solution().wordBreak(s, strs);
    cout << ans << endl;
    while (1);
}