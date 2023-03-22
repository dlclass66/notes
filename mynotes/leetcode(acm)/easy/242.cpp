//输入格式 第一行为第一个字符串 第二行为第二个字符串
//注意数组元素不会默认初始化为0
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        array<int, 26> hash = { 0 };//需要初始化
        for (char i : s) {
            hash[i - 'a']++;
        }
        for (char i : t) {
            hash[i - 'a']--;
        }
        int count = 0;
        for (int i : hash) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    string s;
    string t;
    cin >> s >> t;
    cout << Solution().isAnagram(s, t);
    while (1);
}