//回溯算法 同一层共享的不要用全局变量 


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> ans;
    vector<string> vec;
    vector<vector<string>> solveNQueens(int n) {
        vec.reserve(n);
        backtrack(n, 0);
        return ans;
    }
    void backtrack(int n, int cur) {
        if (vec.size() == n) {
            ans.push_back(vec);
            return;
        }
        string s;
        for (int i = 0; i < n - 1; i++) {
            s.push_back('.');
        }
        for (int i = 0; i < n; i++) {
            if (qualify(cur, i)) {
                s.insert(s.begin() + i, 'Q');
                vec.push_back(s);
                backtrack(n, cur + 1);
                s.erase(s.begin() + i);
                vec.pop_back();
            }
        }
    }
    bool qualify(int x, int y) {
        for (int i = 0; i < x; i++) {
            int j = 0;
            while (vec[i][j] == '.') {
                j++;
            }
            if (y == j || y == j + x - i || y == j - x + i) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    int n = 0;
    cin >> n;
    vector<vector<string>> ans = Solution().solveNQueens(n);
    for (int i = 0; i < ans.size(); i++) {
        for (string& j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}