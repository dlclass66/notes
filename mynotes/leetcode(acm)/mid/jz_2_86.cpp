//先用动态规划得到dp[i][j] 下标为i - 1 到 j - 1的字符串是否为回文串
//然后回溯得到所有的分割方法





#include <iostream>
#include <vector>
#include <string>


using namespace std;



class Solution {
public:
    vector<vector<string>> ans;
    vector<string> vec;
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s) {
        dp = vector<vector<bool>>(s.size() + 1, vector<bool>(s.size() + 1, false));
        for (int i = s.size(); i >= 1; i--) {
            dp[i][i] = true;
            for (int j = i + 1; j <= s.size(); j++) {
                if (s[i - 1] == s[j - 1]) {
                    if (j == i + 1) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
            }
        }
        help(0, s);
        return ans;
    }
    void help(int start, string& s) {
        if (start == s.size()) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start + 1][i + 1]) {
                vec.push_back(s.substr(start, i - start + 1));
                help(i + 1, s);
                vec.pop_back();
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    vector<vector<string>> ans = Solution().partition(s);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    while (1);
}