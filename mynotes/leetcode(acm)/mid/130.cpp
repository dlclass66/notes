//输入格式 每行为字符数组 字符之间用空格隔开
//可以不用visited数组 先扫描边界上的点把‘O’改为其他的  然后再遍历中间的 把‘O’ 改为‘X’ 其他的改回‘O’即可


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> div;
    void solve(vector<vector<char>>& board) {
        div = vector<vector<int>>{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (visited[i][0] == 0 && board[i][0] == 'O') {
                bfs(board, visited, i, 0, false);
            }
            if (visited[i][n - 1] == 0 && board[i][n - 1] == 'O') {
                bfs(board, visited, i, n - 1, false);
            }
        }
        for (int i = 0; i < n; i++) {
            if (visited[0][i] == 0 && board[0][i] == 'O') {
                bfs(board, visited, 0, i, false);
            }
            if (visited[m - 1][i] == 0 && board[m - 1][i] == 'O') {
                bfs(board, visited, m - 1, i, false);
            }
        }
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'O') {
                    bfs(board, visited, i, j, true);
                }
            }
        }
    }
    void bfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x, int y,
        bool in) {
        int m = board.size();
        int n = board[0].size();
        queue<int> qu;
        qu.push(x);
        qu.push(y);
        visited[x][y] = 1;
        while (!qu.empty()) {
            int tempx = qu.front();
            qu.pop();
            int tempy = qu.front();
            qu.pop();
            if (in) {
                board[tempx][tempy] = 'X';
            }
            for (int i = 0; i < 4; i++) {
                int nextx = tempx + div[i][0];
                int nexty = tempy + div[i][1];
                if (nextx >= m || nextx < 0) {
                    continue;
                }
                if (nexty >= n || nexty < 0) {
                    continue;
                }
                if (visited[nextx][nexty] == 1 || board[nextx][nexty] == 'X') {
                    continue;
                }
                qu.push(nextx);
                qu.push(nexty);
                visited[nextx][nexty] = 1;
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
    Solution().solve(graph);
    for (int i = 0; i < graph.size(); i++) {
        for (char ch : graph[i]) {
            cout << ch << ' ';
        }
        cout << endl;
    }
    while (1);
}