//输入格式 第一行s 第二行p 
//使用hash数组判断是否为异位词 注意如果s的长度小于p 返回空vector
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) {
            return ans;
        }
        array<int, 26> hash{ 0 };
        for (char i : p) {
            hash[i - 'a']++;
        }
        int start = 0;
        int end = p.size() - 1;
        for (int i = start; i <= end; i++) {
            hash[s[i] - 'a']--;
        }
        while (end < s.size() - 1) {
            if (hash0(hash)) {
                ans.push_back(start);
            }
            hash[s[start] - 'a']++;
            hash[s[end + 1] - 'a']--;
            start++;
            end++;
        }
        if (hash0(hash)) {
            ans.push_back(start);
        }
        return ans;
    }
    bool hash0(array<int, 26> hash) {
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
    string p;
    cin >> s >> p;
    vector<int> ans = Solution().findAnagrams(s, p);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}