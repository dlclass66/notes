//输入格式 二维char数组 每行一个char数组
//使用动态规划 dp[i][j]表示以下标[i - 1][j - 1]为正方形右下角的正方形的最大边长 其与dp[i - 1][j] dp[i - 1][j - 1] dp[i][j - 1]有关
//开始时尝试使用分别判断每个格最大的 会超时


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size() + 1,
            vector<int>(matrix[0].size() + 1, 0));
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min(dp[i - 1][j - 1],
                        min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    ans = max(dp[i][j], ans);
                }
            }
        }
        return ans * ans;
    }
};



int main() {
    char num = 0;
    vector<char> nums;
    vector<vector<char>> vec;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            vec.push_back(nums);
            nums.clear();
        }
    }
    vec.push_back(nums);
    int ans = Solution().maximalSquare(vec);
    cout << ans;
    while (1);
}