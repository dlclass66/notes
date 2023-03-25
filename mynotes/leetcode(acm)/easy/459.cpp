//暴力解法
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int length = 1;
        while (length <= s.length() / 2) {
            if (s.length() % length != 0) {
                length++;
                continue;
            }
            bool ok = true;
            for (int j = 0; j < length; j++) {
                for (int i = length; i + j < s.length(); i += length) {
                    if (s[j] != s[i + j]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) {
                    break;
                }
            }
            if (ok) {
                return true;
            }
            length++;
        }
        return false;
    }
};
int main() {
    string s1;
    cin >> s1;
    cout << Solution().repeatedSubstringPattern(s1);
    while (1);
}

// 第二种方法 s能由自己的子串重复构成 那么两个s拼起来 一定含有一个s（去掉首尾字符）
//使用了find 底层应该也是kmp算法
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.length() - 1, 1);
        t.erase(0, 1);
        return t.find(s) != t.npos;
    }
};