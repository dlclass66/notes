//使用动态规划 二维dp数组记录i开始j结束的字符串是否为回文串
//也可以使用双指针



#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        vector<int> ans(2, 0);
        int max = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[j] == s[i]) {
                    if (j - i <= 1) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] == 1 && j - i + 1 > max) {
                        max = j - i + 1;
                        ans[0] = i;
                        ans[1] = j;
                    }
                }
            }
        }
        return s.substr(ans[0], max);
    }
};


int main() {
    string str;
    cin >> str;
    string ans = Solution().longestPalindrome(str);
    cout << ans;
    while (1);
}