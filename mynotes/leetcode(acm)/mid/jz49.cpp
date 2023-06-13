//最开始准备一个一个判断 用unordered_set存储丑数 但是超时了
//可以用动态规划 因为一个较大的丑数一定是由前面的丑数乘以2或者3或者5得到的
//用三个指针 分别指向乘以2或者3或者5的丑数的位置 每次取最小的那个丑数 且指针后移
//用三个并列的if去重




#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0;
        int b = 0;
        int c = 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); i++) {
            int anum = dp[a] * 2;
            int bnum = dp[b] * 3;
            int cnum = dp[c] * 5;
            dp[i] = min(anum, min(bnum, cnum));
            if (dp[i] == anum) {
                a++;
            }
            if (dp[i] == bnum) {
                b++;
            }
            if (dp[i] == cnum) {
                c++;
            }
        }
        return dp.back();
    }
};

int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().nthUglyNumber(num);
    cout << ans;
    while (1);
}