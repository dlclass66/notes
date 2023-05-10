//输入格式 先输入word 再分行输入二维char数组
//先遍历board找到word的开始字符 再dfs 注意需要visited数组


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<int>> dir;
    bool exist(vector<vector<char>>& board, string word) {
        dir = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    visited = vector<vector<int>>(board.size(),
                        vector<int>(board[0].size(), 0));
                    visited[i][j] = 1;
                    if (help(board, word, 1, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool help(vector<vector<char>>& board, string word, int n, int x, int y) {
        if (n >= word.size()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int tempi = x + dir[i][0];
            int tempj = y + dir[i][1];
            if (tempi < 0 || tempi >= board.size() || tempj < 0 ||
                tempj >= board[0].size()) {
                continue;
            }
            if (board[tempi][tempj] == word[n] && visited[tempi][tempj] == 0) {
                visited[tempi][tempj] = 1;
                if (help(board, word, n + 1, tempi, tempj)) {
                    return true;
                }
                visited[tempi][tempj] = 0;
            }
        }
        return false;
    }
};



int main() {
    string str;
    cin >> str;
    char ch = 'a';
    vector<char> chs;
    vector<vector<char>> board;
    while (cin >> ch) {
        chs.push_back(ch);
        if (getchar() == '\n') {
            board.push_back(chs);
            chs.clear();
        }
    }
    if (!chs.empty()) {
        board.push_back(chs);
    }
    bool ans = Solution().exist(board, str);
    cout << ans;
    while (1);
}