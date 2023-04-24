//回溯 注意substr的参数 第一个为起始偏移量 第二个为子字符串长度
//判断是否为字符串可以事先计算出s的所有字符串是否为回文串


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<string>> ans;
    vector<string> vec;
    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return ans;
    }
    void backtrack(string& s, int start) {
        if (start == s.size()) {
            ans.push_back(vec);
            return;
        }
        for (int j = start; j < s.size(); j++) {
            if (qualify(s, start, j)) {
                vec.push_back(s.substr(start, j - start + 1));
                backtrack(s, j + 1);
                vec.pop_back();
            }
        }
    }
    bool qualify(string& str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
int main() {
    string str;
    cin >> str;
    vector<vector<string>> ans = Solution().partition(str);
    for (int i = 0; i < ans.size(); i++) {
        for (string j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}