//使用滑动窗口和hash数组 题目要求变位词顺序和原词不能一样 但是似乎也可以


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) {
            return ans;
        }
        vector<int> hash(26, 0);
        for (int i = 0; i < p.size(); i++) {
            hash[p[i] - 'a']++;
        }
        for (int i = 0; i < p.size(); i++) {
            hash[s[i] - 'a']--;
        }
        int left = 0;
        int right = p.size() - 1;
        if (qualify(hash)) {
            ans.push_back(left);
        }
        left++;
        right++;
        while (right < s.size()) {
            hash[s[right] - 'a']--;
            hash[s[left - 1] - 'a']++;
            if (hash[s[left - 1] - 'a'] != 0 || hash[s[right] - 'a'] != 0) {

            }
            else {
                if (qualify(hash)) {
                    ans.push_back(left);
                }
            }
            left++;
            right++;
        }
        return ans;
    }
    bool qualify(vector<int>& hash) {
        for (int i : hash) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string str;
    cin >> str;
    string p;
    cin >> p;
    vector<int> ans = Solution().findAnagrams(str, p);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}