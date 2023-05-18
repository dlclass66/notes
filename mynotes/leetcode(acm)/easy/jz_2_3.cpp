//动态规划 奇数比前一个偶数多一 （最后一位由0变1）偶数和右移一位对应的数相同（因为最后一位是0）



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            if (i % 2 == 1) {
                dp[i] = dp[i - 1] + 1;
            }
            else {
                dp[i] = dp[i / 2];
            }
        }
        return dp;
    }
};



int main() {
    int num = 0;
    cin >> num;
    vector<int> ans = Solution().countBits(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}