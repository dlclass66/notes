//先去掉空格 找到e的位置 判断后面是不是整数 前面是不是小数或者整数



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool isNumber(string s) {
        int start = 0;
        while (start < s.size()) {
            if (s[start] != ' ') {
                break;
            }
            start++;
        }
        if (start >= s.size()) {
            return false;
        }
        int end = s.size() - 1;
        while (end >= 0) {
            if (s[end] != ' ') {
                break;
            }
            end--;
        }
        int eindex = start;
        while (eindex <= end) {
            if (s[eindex] == 'e' || s[eindex] == 'E') {
                break;
            }
            eindex++;
        }
        bool ee = true;
        if (eindex > end) {
            ee = false;
        }
        if (ee) {
            return isint(s, eindex + 1, end) && (isint(s, start, eindex - 1) || isdouble(s, start, eindex - 1));
        }
        else {
            return isint(s, start, end) || isdouble(s, start, end);
        }
        return false;
    }
    bool isint(string& s, int start, int end) {
        if (s[start] == '+' || s[start] == '-') {
            start++;
        }
        if (end - start < 0) {
            return false;
        }
        while (start <= end) {
            if (s[start] - '0' > 9 || s[start] - '0' < 0) {
                return false;
            }
            start++;
        }
        return true;
    }
    bool isdouble(string& s, int start, int end) {
        if (s[start] == '+' || s[start] == '-') {
            start++;
        }
        if (end - start < 1) {
            return false;
        }
        int point = 0;
        while (start <= end) {
            if (s[start] == '.') {
                point++;
                if (point > 1) {
                    return false;
                }
            }
            else if (s[start] - '0' < 0 || s[start] - '0' > 9) {
                return false;
            }
            start++;
        }
        if (point == 0) {
            return false;
        }
        return true;
    }
};


int main() {
    string str;
    cin >> str;
    bool ans = Solution().isNumber(str);
    cout << ans;
    while (1);
}