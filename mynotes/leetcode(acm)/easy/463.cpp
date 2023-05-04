//输入格式 二维数组 每行一个一维数组 数字间用空格隔开
//遍历每一个格 如果是陆地 周围每有一个海的格 就有一条边


#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                int num = 4;
                for (int k = 0; k < 4; k++) {
                    int tempi = i + dir[k][0];
                    int tempj = j + dir[k][1];
                    if (tempi >= 0 && tempi < grid.size() &&
                        tempj >= 0 && tempj < grid[0].size() && grid[tempi][tempj] == 1) {
                        num--;
                    }
                }
                ans += num;
            }
        }
        return ans;
    }
};


int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> vec;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            vec.push_back(nums);
            nums.clear();
        }
    }
    vec.push_back(nums);
    int ans = Solution().islandPerimeter(vec);
    cout << ans;
    while (1);
}