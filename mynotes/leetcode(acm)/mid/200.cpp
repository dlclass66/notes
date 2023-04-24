//输入格式 每行一个字符数组 字符间用空格隔开
//可以使用bfs 或dfs 搜索标记 每步有4个方向可以走 上下左右


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> div;
    int numIslands(vector<vector<char>>& grid) {
        div = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (visited[i][j] == 1 || grid[i][j] == '0') {
                    continue;
                }
                bfs(grid, visited, i, j);
                count++;
            }
        }
        return count;
    }
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int x, int y) {
        queue<pair<int, int>> qu;
        qu.push({ x, y });
        visited[x][y] = 1;
        int m = grid.size();
        int n = grid[0].size();
        while (!qu.empty()) {
            auto pa = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                auto pa1 = pa;
                pa1.first += div[i][0];
                pa1.second += div[i][1];
                if (pa1.first < m && pa1.first >= 0 &&
                    pa1.second < n && pa1.second >= 0 &&
                    grid[pa1.first][pa1.second] == '1' &&
                    visited[pa1.first][pa1.second] == 0) {
                    qu.push(pa1);
                    visited[pa1.first][pa1.second] = 1;
                }
            }
        }
    }
};
int main() {
    char ch;
    vector<vector<char>> graph;
    vector<char> chs;
    while (cin >> ch) {
        chs.push_back(ch);
        if (getchar() == '\n') {
            graph.push_back(chs);
            chs.clear();
        }
    }
    graph.push_back(chs);
    int ans = Solution().numIslands(graph);
    cout << ans;
    while (1);
}