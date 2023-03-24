//先用erase函数去掉多余空格 然后反转整个字符串 最后再依次反转每个单词
//erase函数复杂度较高 考虑使用双指针去掉多余空格 再resize
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        while (s[0] == ' ') {
            s.erase(0, 1);
        }
        while (i < s.length()) {
            if (s[i] == ' ' && s[i - 1] == ' ') {
                s.erase(i, 1);
            }
            i++;
        }
        if (s[s.length() - 1] == ' ') {
            s.erase(s.length() - 1);
        }
        revers(s, 0, s.length() - 1);
        int begin = 0;
        int end = 0;
        while (end < s.length()) {
            if (s[end] != ' ') {
                end++;
                continue;
            }
            revers(s, begin, end - 1);
            begin = end + 1;
            end = begin;
        }
        revers(s, begin, s.length() - 1);
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
    getline(cin, s);
    string ans = Solution().reverseWords(s);
    cout << ans;
    while (1);
}

// 双指针法 要注意最后slow停留的位置
class Solution {
public:
    string reverseWords(string s) {
        int slow = 0;
        int fast = 0;
        while (s[fast] == ' ') {
            fast++;
        }
        while (fast < s.length()) {
            if (s[fast] == ' ' && s[fast - 1] == ' ') {
                fast++;
            }
            else {
                s[slow] = s[fast];
                slow++;
                fast++;
            }
        }
        if (s[slow - 1] == ' ') {
            slow--;
        }
        s.resize(slow);
        revers(s, 0, s.length() - 1);
        int begin = 0;
        int end = 0;
        while (end < s.length()) {
            if (s[end] != ' ') {
                end++;
                continue;
            }
            revers(s, begin, end - 1);
            begin = end + 1;
            end = begin;
        }
        revers(s, begin, s.length() - 1);
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