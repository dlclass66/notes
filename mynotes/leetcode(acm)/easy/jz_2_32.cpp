//分行输入两个字符串
//用hash表统计字符串各字符出现的次数




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size() || s == t) {
            return false;
        }
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            hash[t[i] - 'a']--;
            if (hash[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};



int main() {
    string s;
    cin >> s;
    string t;
    cin >> t;
    bool ans = Solution().isAnagram(s, t);
    cout << ans;
    while (1);
}