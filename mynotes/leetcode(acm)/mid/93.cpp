//回溯算法 
//注意插入后字符串temp的变化 对temp的修改最好只在循环中 进入递归前进行 方便回溯撤销 



#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> ans;
    string temp;
    int count = 0;
    vector<string> restoreIpAddresses(string s) {
        temp = s;
        backtrack(s, 0);
        return ans;
    }
    void backtrack(string& s, int start) {
        if (start == s.size() && count == 4) {
            ans.push_back(temp);
            ans.back().pop_back();
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (qualify(s, start, i) && count <= 3) {
                temp.insert(temp.begin() + i + 1 + count, '.');
                count++;
                backtrack(s, i + 1);
                count--;
                temp.erase(temp.begin() + i + 1 + count);
            }
            else {
                break;
            }
        }
    }
    bool qualify(string& s, int start, int end) {
        if (start == end) {
            return true;
        }
        if (s[start] == '0') {
            return false;
        }
        int num = stoi(s.substr(start, end - start + 1));
        return num <= 255;
    }
};
int main() {
    string str;
    cin >> str;
    vector<string> ans = Solution().restoreIpAddresses(str);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    while (1);
}