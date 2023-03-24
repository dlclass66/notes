//输入格式 字符数组 字符之间用空格隔开
//输出格式 与输入一致
//使用双指针即可
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            swap(s, start, end);
            start++;
            end--;
        }
    }
    void swap(vector<char>& s, int a, int b) {
        char temp = s[a];
        s[a] = s[b];
        s[b] = temp;
    }
};
int main() {
    char ch = 'a';
    vector<char> s;
    while (cin >> ch) {
        s.push_back(ch);
    }
    Solution().reverseString(s);
    for (char i : s) {
        cout << i << ' ';
    }
    while (1);
}