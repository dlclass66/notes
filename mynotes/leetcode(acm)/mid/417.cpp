//输入格式 分行输入int数组 每行的int数组 数字间用空格隔开
//从边界出发 能到的进行标记 如果从太平洋和大西洋都能到达就是符合条件的位置



#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> div;
    vector<vector<int>> qualify;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        div = vector<vector<int>>{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        ans.reserve(m * n);
        vector<int> vec(2, 0);
        qualify = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            if (qualify[i][0] == 0 || qualify[i][0] == 2) {
                bfs(heights, i, 0, 1);
            }
            if (qualify[i][n - 1] == 0 || qualify[i][n - 1] == 1) {
                bfs(heights, i, n - 1, 2);
            }
        }
        for (int i = 0; i < n; i++) {
            if (qualify[0][i] == 0 || qualify[0][i] == 2) {
                bfs(heights, 0, i, 1);
            }
            if (qualify[m - 1][i] == 0 || qualify[m - 1][i] == 1) {
                bfs(heights, m - 1, i, 2);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (qualify[i][j] == 3) {
                    vec[0] = i;
                    vec[1] = j;
                    ans.push_back(vec);
                }
            }
        }
        return ans;
    }
    void bfs(vector<vector<int>>& heights, int x, int y, int mode) {
        int m = heights.size();
        int n = heights[0].size();
        queue<int> qu;
        qu.push(x);
        qu.push(y);
        if (mode == 1) {
            if (qualify[x][y] == 2) {
                qualify[x][y] = 3;
            }
            else {
                qualify[x][y] = 1;
            }
        }
        if (mode == 2) {
            if (qualify[x][y] == 1) {
                qualify[x][y] = 3;
            }
            else {
                qualify[x][y] = 2;
            }
        }
        while (!qu.empty()) {
            int tempx = qu.front();
            qu.pop();
            int tempy = qu.front();
            qu.pop();
            for (int i = 0; i < 4; i++) {
                int nextx = tempx + div[i][0];
                int nexty = tempy + div[i][1];
                if (nextx < 0 || nextx >= m) {
                    continue;
                }
                if (nexty < 0 || nexty >= n) {
                    continue;
                }
                if (heights[nextx][nexty] < heights[tempx][tempy]) {
                    continue;
                }
                if (qualify[nextx][nexty] == 3) {
                    continue;
                }
                if (mode == 1) {
                    if (qualify[nextx][nexty] == 1) {
                        continue;
                    }
                    if (qualify[nextx][nexty] == 2) {
                        qualify[nextx][nexty] = 3;
                    }
                    else {
                        qualify[nextx][nexty] = 1;
                    }
                }
                if (mode == 2) {
                    if (qualify[nextx][nexty] == 2) {
                        continue;
                    }
                    if (qualify[nextx][nexty] == 1) {
                        qualify[nextx][nexty] = 3;
                    }
                    else {
                        qualify[nextx][nexty] = 2;
                    }
                }
                qu.push(nextx);
                qu.push(nexty);
            }
        }
    }
};
int main() {
    int num;
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
    vector<vector<int>> ans = Solution().pacificAtlantic(graph);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}