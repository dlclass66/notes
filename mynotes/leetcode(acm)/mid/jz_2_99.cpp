//动态规划 可以直接使用grid当作dp数组


#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 1; i < grid[0].size(); i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int i = 1; i < grid.size(); i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
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
    int ans = Solution().minPathSum(grid);
    cout << ans;
    while (1);
}