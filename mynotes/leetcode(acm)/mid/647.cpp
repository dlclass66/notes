//动态规划 使用二维数组 dp数组的含义是以i开始以j结束的区间（左右都是闭）是否为回文串 
//还可以使用双指针法 遍历s 以一个字符或两个字符为中心扩散 

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int ans = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
int main() {
    string s;
    cin >> s;
    int ans = Solution().countSubstrings(s);
    cout << ans << endl;
    while (1);
}