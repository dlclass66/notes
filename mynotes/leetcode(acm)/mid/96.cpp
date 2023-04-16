//动态数组 注意将和分解为不同根节点的可能的情况的和 由根节点可以得到左右子树的可能的情况个数 初始化了dp[2] 所以n = 1时要单独处理
//根据根节点的数字转换为前面已经得到的数组 得到递推公式 其实也可以不单独处理n = 1 因为可以递推得到dp[2]


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
        if (n < 2) {
            return 1;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[0] = 1;
        for (int i = 3; i < n + 1; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[i - j] * dp[j - 1];
            }
        }
        return dp[n];
    }
};
int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().numTrees(num);
    cout << ans << endl;
    while (1);
}