//输入格式 每行一个数组 数字中间用空格隔开
//使用动态规划即可 二维数组



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            path[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            path[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }
        return path[m - 1][n - 1];
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> nums_2;
    bool init = false;
    int i = 0;
    while (cin >> num) {
        if (init) {
            nums[i] = num;
            i++;
        }
        else {
            nums.push_back(num);
        }
        if (getchar() == '\n') {
            nums_2.push_back(nums);
            i = 0;
            init = true;
        }
    }
    nums_2.push_back(nums);
    int ans = Solution().uniquePathsWithObstacles(nums_2);
    cout << ans << endl;
    while (1);
}