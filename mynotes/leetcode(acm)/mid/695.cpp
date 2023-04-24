//输入格式 每行一个int数组 数字间用空格隔开
//可以使用bfs 每次判断当前面积是否大于最大面积即可



#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> div;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        div = vector<vector<int>>{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || visited[i][j] == 1) {
                    continue;
                }
                ans = max(bfs(grid, visited, i, j), ans);
            }
        }
        return ans;
    }
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> qu;
        qu.push({ x, y });
        visited[x][y] = 1;
        while (!qu.empty()) {
            int tempx = qu.front().first;
            int tempy = qu.front().second;
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
                if (grid[nextx][nexty] == 0 || visited[nextx][nexty] == 1) {
                    continue;
                }
                visited[nextx][nexty] = 1;
                qu.push({ nextx, nexty });
            }
        }
        return ans;
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
    int ans = Solution().maxAreaOfIsland(graph);
    cout << ans;
    while (1);
}