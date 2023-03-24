//先反转整个字符串再分别反转
//输入格式 第一行为字符串 第二行为n
//也可以使用标准库的reverse函数 参数为起始迭代器和终止迭代器
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s, 0, s.length() - 1);
        reverse(s, 0, s.length() - n - 1);
        reverse(s, s.length() - n, s.length() - 1);
        return s;
    }
private:
    void reverse(string& s, int begin, int end) {
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
    int n = 0;
    getline(cin, s);
    cin >> n;
    string ans = Solution().reverseLeftWords(s, n);
    cout << ans;
    while (1);
}