//输入格式 每行一个字符串数组 字符之间用空格隔开
//回溯函数使用返回bool 这样找到解法可以直接返回而不会回溯 


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int count = 0;
    void solveSudoku(vector<vector<char>>& board) {
        backtrace(board, 0, 0);
    }
    bool backtrace(vector<vector<char>>& board, int cur, int i) {
        if (cur == 9 && i == 0) {
            return true;
        }
        if (board[cur][i] != '.') {
            if (i == 8) {
                return backtrace(board, cur + 1, 0);
            }
            else {
                return backtrace(board, cur, i + 1);
            }
        }
        for (int k = 1; k < 10; k++) {
            if (qualify(board, cur, i, k)) {
                board[cur][i] = '0' + k;
                count++;
                if (i == 8) {
                    if (backtrace(board, cur + 1, 0)) {
                        return true;
                    }
                }
                else {
                    if (backtrace(board, cur, i + 1)) {
                        return true;
                    }
                    board[cur][i] = '.';
                    count--;
                }
            }
        }
        return false;
    }
    bool qualify(vector<vector<char>>& board, int x, int y, int k) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == ('0' + k) || board[i][y] == ('0' + k)) {
                return false;
            }
        }
        int startx = x / 3 * 3;
        int starty = y / 3 * 3;
        for (int i = startx; i < startx + 3; i++) {
            for (int j = starty; j < starty + 3; j++) {
                if (board[i][j] == '0' + k) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main() {
    char ch;
    vector<vector<char>> board;
    vector<char> temp;
    while (cin >> ch) {
        temp.push_back(ch);
        if (getchar() == '\n') {
            board.push_back(temp);
            temp.clear();
        }
    }
    board.push_back(temp);
    Solution().solveSudoku(board);
    for (int i = 0; i < board.size(); i++) {
        for (char j : board[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}