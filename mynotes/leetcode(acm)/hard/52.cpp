//运用回溯算法 循环列 因为一行最多一个皇后 填上了就跳到下一行


#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    int ans = 0;
    int totalNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        help(board, 0);
        return ans;
    }
    bool qualify(vector<vector<int>>& board, int x, int y) {
        for (int i = 0; i < x; i++) {
            if (board[i][y] == 1) {
                return false;
            }
            if (y + x - i < board.size() && board[i][y + x - i] == 1) {
                return false;
            }
            if (y - x + i >= 0 && board[i][y - x + i] == 1) {
                return false;
            }
        }
        for (int i = 0; i < y; i++) {
            if (board[x][i] == 1) {
                return false;
            }
        }
        return true;
    }
    void help(vector<vector<int>>& board, int x) {
        if (x == board.size()) {
            ans++;
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            if (qualify(board, x, i)) {
                board[x][i] = 1;
                help(board, x + 1);
                board[x][i] = 0;
            }
        }
    }
};


int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().totalNQueens(num);
    cout << ans;
    while (1);
}