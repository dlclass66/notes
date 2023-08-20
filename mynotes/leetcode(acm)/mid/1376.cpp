//输入格式 每行一个参数 数组数字用空格隔开
//思路就是先建立邻接表 每个成员的直属下属 然后用dfs或者bfs遍历

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> inftime;
    int maxtime = 0;
    vector<vector<int>> emp;
    void help(int manager, vector<int>& informTime) {
        if (emp[manager].empty()) {
            maxtime = max(maxtime, inftime[manager]);
        }
        for (int i = 0; i < emp[manager].size(); i++) {
            inftime[emp[manager][i]] =
                inftime[manager] + informTime[manager];
            help(emp[manager][i], informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        emp = vector<vector<int>>(n);
        inftime = vector<int>(n);
        for (int i = 0; i < n; i++) {
            if (i == headID) {
                continue;
            }
            emp[manager[i]].push_back(i);
        }
        help(headID, informTime);
        return maxtime;
    }
};


int main() {
    int n = 0;
    cin >> n;
    int headid = 0;
    cin >> headid;
    vector<int> man;
    int num = 0;
    while (cin >> num) {
        man.push_back(num);
        if(getchar() == '\n')
			break;
    }
    vector<int> info;
    while (cin >> num) {
        info.push_back(num);
        if (getchar() == '\n')
            break;
    }
    int ans = Solution().numOfMinutes(n, headid, man, info);
    cout << ans;
    while(1);
}
