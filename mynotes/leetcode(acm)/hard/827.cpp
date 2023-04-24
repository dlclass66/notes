//输入格式 每行为一个int数组 数字间用空格隔开
//虽然不能把岛屿的每个块都改成该岛屿的大小 但是可以给其一个编号 利用编号映射得到岛屿的大小 
//数字为0的岛屿块 如果换成1 其上下左右的岛屿的大小的和就是所求值 注意其上下左右可能有同一个编号的岛屿 要排除 


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<vector<int>> div;
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        div = vector<vector<int>>{ {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        int m = grid.size();
        int n = grid[0].size();
        vector<int> hash(m * n + 1, 0);
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int num = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    hash[num] = bfs(grid, visited, i, j, num);
                    num++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    ans = max(ans, qualify(grid, i, j, hash));
                }
            }
        }
        if (ans == 0) {
            return m * n;
        }
        else {
            return ans;
        }
    }
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int x, int y,
        int num) {
        queue<int> qu;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        qu.push(x);
        qu.push(y);
        visited[x][y] = 1;
        while (!qu.empty()) {
            int tempx = qu.front();
            qu.pop();
            int tempy = qu.front();
            qu.pop();
            grid[tempx][tempy] = num;
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
                qu.push(nextx);
                qu.push(nexty);
                visited[nextx][nexty] = 1;
            }
        }
        return ans;
    }
    int qualify(vector<vector<int>>& grid, int x, int y, vector<int>& hash) {
        int count = 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> nums(4, 0);
        for (int i = 0; i < 4; i++) {
            int tempx = x + div[i][0];
            int tempy = y + div[i][1];
            if (tempx < 0 || tempx >= m) {
                continue;
            }
            if (tempy < 0 || tempy >= n) {
                continue;
            }
            if (grid[tempx][tempy] != 0) {
                int num = grid[tempx][tempy];
                int j = 0;
                while (j < i) {
                    if (nums[j] == num) {
                        break;
                    }
                    j++;
                }
                if (j == i) {
                    count += hash[num];
                    nums[i] = num;
                }
            }
        }
        return count;
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
    int ans = Solution().largestIsland(graph);
    cout << ans;
    while (1);
}