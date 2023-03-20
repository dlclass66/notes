//有一些难度 输入格式 第一行输入第一个字符串 第二行输入第二个
//要注意是否需要循环
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int chars = getchar_num(s, s.length());
        int chart = getchar_num(t, t.length());
        while (chars != -1 || chart != -1) {
            if (chars == -1 || chart == -1 || s[chars] != t[chart]) {
                return false;
            }
            chars = getchar_num(s, chars);
            chart = getchar_num(t, chart);
        }
        return true;
    }
private:
    int getchar_num(string& s, int end) {
        if (end < 1) {
            return -1;
        }
        int ptr = end - 1;
        int count = 0;
        while (ptr >= 0 && s[ptr] == '#') { //这里需要循环 有可能又遇到‘#’
            while (ptr >= 0 && s[ptr] == '#') {
                ptr--;
                count++;
            }
            while (count > 0 && ptr >= 0) {
                if (s[ptr] == '#') {
                    count++;
                    ptr--;
                }
                else {
                    count--;
                    ptr--;
                }
            }
        }
        return ptr;
    }
};
int main() {
    int num = 0;
    int target = 0;
    string s;
    string t;
    cin >> s >> t;
    bool ans = Solution().backspaceCompare(s, t);
    cout << ans;
    while (1);
}