//输入格式 每行为一个int数组 数字间用空格隔开
//使用深搜或广搜看从0出发能到达的房间个数



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int count = 0;
    vector<int> visited;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited = vector<int>(rooms.size(), 0);
        dfs(rooms, 0);
        return count == rooms.size();
    }
    void dfs(vector<vector<int>>& rooms, int cur) {
        if (visited[cur] == 1) {
            return;
        }
        visited[cur] = 1;
        count++;
        for (int i = 0; i < rooms[cur].size(); i++) {
            dfs(rooms, rooms[cur][i]);
        }
    }
};
int main() {
    int num = 0;
    vector<int> vec;
    vector<vector<int>> nums;
    while (cin >> num) {
        vec.push_back(num);
        if (getchar() == '\n') {
            nums.push_back(vec);
            vec.clear();
        }
    }
    nums.push_back(vec);
    bool ans = Solution().canVisitAllRooms(nums);
    cout << ans;
    while (1);
}