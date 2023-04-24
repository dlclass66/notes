//输入格式 每行为一个int数组 数字间用空格隔开
//可以dfs或者bfs 如果有边界 就标记为false 返回0 如果没有 就返回岛的大小


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> div;
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        div = vector<vector<int>>{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1 || grid[i][j] == 0) {
                    continue;
                }
                ans += bfs(grid, visited, i, j);
            }
        }
        return ans;
    }
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        bool qualify = false;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<int> qu;
        qu.push(x);
        qu.push(y);
        visited[x][y] = 1;
        if (x == 0 || x == m - 1) {
            qualify = true;
        }
        if (y == 0 || y == n - 1) {
            qualify = true;
        }
        while (!qu.empty()) {
            int tempx = qu.front();
            qu.pop();
            int tempy = qu.front();
            qu.pop();
            ans++;
            for (int i = 0; i < 4; i++) {
                int nextx = tempx + div[i][0];
                int nexty = tempy + div[i][1];
                if (nextx < 0 || nextx >= m) {
                    continue;
                }
                if (nexty < 0 || nexty >= n) {
                    continue;
                }
                if (visited[nextx][nexty] == 1 || grid[nextx][nexty] == 0) {
                    continue;
                }
                if (nextx == 0 || nextx == m - 1) {
                    qualify = true;
                }
                if (nexty == 0 || nexty == n - 1) {
                    qualify = true;
                }
                qu.push(nextx);
                qu.push(nexty);
                visited[nextx][nexty] = 1;
            }
        }
        if (qualify) {
            return 0;
        }
        else {
            return ans;
        }
    }
};
int main() {
    int num = 0;
    vector<vector<int>> graph;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            graph.push_back(nums);
            nums.clear();
        }
    }
    graph.push_back(nums);
    int ans = Solution().numEnclaves(graph);
    cout << ans;
    while (1);
}