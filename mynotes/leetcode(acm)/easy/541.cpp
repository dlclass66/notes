//输入格式 字符串和k用空格隔开
//按段反转即可
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int begin = 0;
        int end = 2 * k - 1;
        while (end < s.length()) {
            revers(s, begin, begin + k - 1);
            begin += 2 * k;
            end += 2 * k;
        }
        if (s.length() - begin < k) {
            revers(s, begin, s.length() - 1);
        }
        else {
            revers(s, begin, begin + k - 1);
        }
        return s;
    }
private:
    void revers(string& s, int begin, int end) {
        while (begin < end) {
            swap(s, begin, end);
            begin++;
            end--;
        }
    }
    void swap(string& s, int a, int b) {
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    }
};
int main() {
    string s;
    int k = 0;
    cin >> s >> k;
    string ans = Solution().reverseStr(s, k);
    cout << ans;
    while (1);
}