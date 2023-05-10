//输入格式 二维数组 每行一个数组 数字间用空格隔开
//动态规划 使用二维数组dp[i][j]表示从左上角到ij的最小路径和 注意第一行和第一列的初始化




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> matrix;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            matrix.push_back(nums);
            nums.clear();
        }
    }
    if (!nums.empty()) {
        matrix.push_back(nums);
    }
    int ans = Solution().minPathSum(matrix);
    cout << ans;
    while (1);
}