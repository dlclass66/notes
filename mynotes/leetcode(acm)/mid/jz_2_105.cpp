//dfs 可以用grid本身当visited数组




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<int>> dir;
    int sum = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        dir = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    sum = 1;
                    grid[i][j] = -1;
                    dfs(i, j, grid);
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
    void dfs(int x, int y, vector<vector<int>>& grid) {
        for (int i = 0; i < dir.size(); i++) {
            int tempx = x + dir[i][0];
            int tempy = y + dir[i][1];
            if (tempx >= grid.size() || tempx < 0 || tempy >= grid[0].size() || tempy < 0) {
                continue;
            }
            if (grid[tempx][tempy] != 1) {
                continue;
            }
            sum++;
            grid[tempx][tempy] = -1;
            dfs(tempx, tempy, grid);
        }
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
    int ans = Solution().maxAreaOfIsland(grid);
    cout << ans;
    while (1);
}