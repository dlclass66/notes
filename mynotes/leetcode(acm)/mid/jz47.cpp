//输入格式 每行一个数组 数字间用空格隔开
//动态规划 为了降低空间复杂度 可以用grid当作dp数组




#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = 1; i <= grid.size(); i++) {
            for (int j = 1; j <= grid[0].size(); j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> grid;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            grid.push_back(nums);
            nums.clear();
        }
    }
    grid.push_back(nums);
    int ans = Solution().maxValue(grid);
    cout << ans;
    while (1);
}