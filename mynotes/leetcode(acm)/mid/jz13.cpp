//dfs 使用visited数组标记已访问的 可以一开始就把不能到的格子标记为true




#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    int count = 0;
    vector<vector<bool>> visited;
    vector<vector<int>> dir;
    int movingCount(int m, int n, int k) {
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    visited[i][j] = qualify(i, j, k);
                }
                else {
                    if ((visited[i - 1][j] && (i - 1) % 10 != 9) || (visited[i][j - 1] && (j - 1) % 10 != 9)) {
                        visited[i][j] = true;
                    }
                    visited[i][j] = qualify(i, j, k);
                }
            }
        }
        visited[0][0] = true;
        dfs(m, n, 0, 0);
        return count;
    }
    bool qualify(int x, int y, int k) {
        string str = to_string(x) + to_string(y);
        int num = 0;
        for (int i = 0; i < str.size(); i++) {
            num += str[i] - '0';
        }
        return num > k;
    }
    void dfs(int m, int n, int x, int y) {
        count++;
        for (int i = 0; i < 4; i++) {
            int tempx = x + dir[i][0];
            int tempy = y + dir[i][1];
            if (tempx >= 0 && tempx < m && tempy >= 0 && tempy < n && !visited[tempx][tempy]) {
                visited[tempx][tempy] = true;
                dfs(m, n, tempx, tempy);
            }
        }
    }
};


int main() {
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
    int k = 0;
    cin >> k;
    int ans = Solution().movingCount(m, n, k);
    cout << ans;
    while (1);
}