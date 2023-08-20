//先去除前面多余的空格 然后判断正负号 然后判断数字是否合法
//用一个longlong记录结果 避免溢出



#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
    bool isnum(char ch) {
        return ch - '0' >= 0 && ch - '0' < 10;
    }
    int myAtoi(string s) {
        int begin = 0;
        while (begin < s.size() && s[begin] == ' ') {
            begin++;
        }
        if (begin == s.size() || !isnum(s[begin]) &&
            s[begin] != '+' && s[begin] != '-') {
            return 0;
        }
        bool neg = false;
        if (s[begin] == '-') {
            neg = true;
            begin++;
        }
        else if (s[begin] == '+') {
            begin++;
        }
        long long ans = 0;
        while (begin < s.size() && ans < INT_MAX) {
            if (!isnum(s[begin])) {
                break;
            }
            ans = ans * 10 + (s[begin] - '0');
            begin++;
        }
        if (ans > INT_MAX) {
            if (neg) {
                return INT_MIN;
            }
            else {
                return INT_MAX;
            }
        }
        if (neg) {
            return -1 * ans;
        }
        else {
            return ans;
        }

    }
};


int main() {
    string str;
    cin >> str;
    int ans = Solution().myAtoi(str);
    cout << ans;
    while (1);
}
