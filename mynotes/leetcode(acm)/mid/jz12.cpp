//输入格式 第一行word 后面每一行一个char数组 char之间用空格隔开
//使用dfs 可以使用visited数组 但更好的方式是将访问过的改为特殊字符 



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<int>> dir;
    int count = 0;
    bool exist(vector<vector<char>>& board, string word) {
        dir = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                count = 0;
                if (dfs(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int x, int y) {
        if (count >= word.size()) {
            return false;
        }
        if (word[count] != board[x][y]) {
            return false;
        }
        if (count + 1 == word.size()) {
            return true;
        }
        board[x][y] = '0';
        count++;
        for (int i = 0; i < 4; i++) {
            int tempx = x + dir[i][0];
            int tempy = y + dir[i][1];
            if (tempx >= 0 && tempx < board.size() && tempy >= 0 && tempy < board[0].size()) {
                if (board[tempx][tempy] != '0') {
                    if (dfs(board, word, tempx, tempy)) {
                        return true;
                    }
                }
            }
        }
        count--;
        board[x][y] = word[count];
        return false;
    }
};


int main() {
    string str;
    cin >> str;
    char ch = '0';
    vector<char> chs;
    vector<vector<char>> matrix;
    while (cin >> ch) {
        chs.push_back(ch);
        if (getchar() == '\n') {
            matrix.push_back(chs);
            chs.clear();
        }
    }
    matrix.push_back(chs);
    bool ans = Solution().exist(matrix, str);
    cout << ans;
    while (1);
}