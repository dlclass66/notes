//因为是求最短路径 所以采用bfs 但是bfs的话需要记录已经走过的路径 用set记录（死亡数组也用同一个set记录）
//数字的变化用一个二维数组表示 0表示第几位 1表示加减




#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;



class Solution {
public:
    vector<vector<int>> dir;
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        dir = { {0, -1}, {1, -1}, {2, -1}, {3, -1}, {0, 1}, {1, 1}, {2, 1}, {3, 1} };
        string temp = "0000";
        if (dead.find(temp) != dead.end()) {
            return -1;
        }
        dead.insert(temp);
        return bfs(temp, target, dead);
    }
    int bfs(string& cur, string& target, unordered_set<string> dead) {
        int ans = 0;
        queue<string> qu;
        qu.push(cur);
        while (!qu.empty()) {
            int size = qu.size();
            while (size > 0) {
                cur = qu.front();
                qu.pop();
                if (cur == target) {
                    return ans;
                }
                for (int i = 0; i < dir.size(); i++) {
                    string temp = cur;
                    if (cur[dir[i][0]] == '0' && dir[i][1] == -1) {
                        cur[dir[i][0]] = '9';
                    }
                    else if (cur[dir[i][0]] == '9' && dir[i][1] == 1) {
                        cur[dir[i][0]] = '0';
                    }
                    else {
                        cur[dir[i][0]] += dir[i][1];
                    }
                    if (dead.find(cur) == dead.end()) {
                        dead.insert(cur);
                        qu.push(cur);
                    }
                    cur = temp;
                }
                size--;
            }
            ans++;
        }
        return -1;
    }
};

int main() {
    string target;
    cin >> target;
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
    }
    int ans = Solution().openLock(strs, target);
    cout << ans;
    while (1);
}