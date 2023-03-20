//输入格式 第一行字符串s 第二行字符串t
//使用滑动窗口 使用unordered_map 储存字符和数量
#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }
        unordered_map<char, int> hmap;
        for (char i : t) {
            hmap[i]++;
        }
        int left = 0;
        int right = 0;
        array<int, 2> landr;
        int minlength = s.length() + 1;
        for (; right < s.length(); right++) {
            if (hmap.find(s[right]) != hmap.end()) {
                hmap[s[right]]--;
            }
            while (zero(hmap)) {
                if (right - left + 1 < minlength) {
                    minlength = right - left + 1;
                    landr[0] = left;
                    landr[1] = right;
                }
                if (hmap.find(s[left]) != hmap.end()) {
                    hmap[s[left]]++;
                }
                left++;
            }
        }
        if (minlength == s.length() + 1) {
            return "";
        }
        return s.substr(landr[0], landr[1] - landr[0] + 1);
    }
    bool zero(unordered_map<char, int>& hmap) {
        for (auto pr : hmap) {
            if (pr.second > 0) {
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
    string ans = Solution().minWindow(s, t);
    cout << ans;
    while (1);
}