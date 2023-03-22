//输入格式 第一行 ransomNote 第二行 magazine
//使用hash数组即可
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        array<int, 26> hash{ 0 };
        for (char i : magazine) {
            hash[i - 'a']++;
        }
        for (char i : ransomNote) {
            hash[i - 'a']--;
            if (hash[i - 'a'] < 0) {
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
    cout << Solution().canConstruct(s, t);
    while (1);
}