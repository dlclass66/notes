//首先得到二维数组 表示i到j的字符串是否为回文串
//动态规划 dp[i] 表示0到i的最少分割次数 通过遍历确定最后一刀的位置


#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    int minCut(string s) {
        vector<vector<int>> qualify(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        qualify[i][j] = 1;
                    }
                    else {
                        qualify[i][j] = qualify[i + 1][j - 1];
                    }
                }
            }
        }
        vector<int> dp(s.size(), INT_MAX);
        for (int i = 0; i < s.size(); i++) {
            if (qualify[0][i] == 1) {
                dp[i] = 0;
                continue;
            }
            for (int j = 1; j <= i; j++) {
                if (qualify[j][i] == 1) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};


int main() {
    string str;
    cin >> str;
    int ans = Solution().minCut(str);
    cout << ans;
    while (1);
}