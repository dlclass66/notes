//输入格式 第一行为字符串数组 字符串之间用空格隔开 第二行为m和n 中间用空格隔开
//01背包 需要使用二维数组 因为有0和1的数量双重限制 注意应该从后往前遍历 因为从前往后会覆盖之前的结果
//可以用一个大的for循环完成 


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> num(strs.size(), { 0, 0 });
        for (int i = 0; i < strs.size(); i++) {
            int zero_num = 0;
            int one_num = 0;
            for (char ch : strs[i]) {
                if (ch == '0') {
                    zero_num++;
                }
                else {
                    one_num++;
                }
            }
            num[i] = pair<int, int>(zero_num, one_num);
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < strs.size(); i++) {
            for (int j = m; j >= num[i].first; j--) {
                for (int k = n; k >= num[i].second; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - num[i].first][k - num[i].second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};
int main() {
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
        if (getchar() == '\n') {
            break;
        }
    }
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    int ans = Solution().findMaxForm(strs, m, n);
    cout << ans << endl;
    while (1);
}