//动态规划 dp[i]表示下标0到i的数字能翻译的字符串的个数 递推关键就是看i和i-1可不可以翻译成一个字母



#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int size = str.size();
        vector<int> dp(size, 0);
        dp[0] = 1;
        for (int i = 1; i < size; i++) {
            int temp = 10 * (str[i - 1] - '0') + (str[i] - '0');
            if (temp > 25 || temp < 10) {
                dp[i] = dp[i - 1];
            }
            else {
                if (i == 1) {
                    dp[i] = 2;
                    continue;
                }
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        return dp[size - 1];
    }
};

int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().translateNum(num);
    cout << ans;
    while (1);
}