//使用hash数组加滑动窗口



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        vector<int> hash(26, 0);
        for (int i = 0; i < s1.size(); i++) {
            hash[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.size(); i++) {
            if (i < s1.size() - 1) {
                hash[s2[i] - 'a']--;
            }
            else if (i == s1.size() - 1) {
                hash[s2[i] - 'a']--;
                if (hash[s2[i] - 'a'] == 0 && qualify(hash)) {
                    return true;
                }
            }
            else {
                hash[s2[i] - 'a']--;
                hash[s2[i - s1.size()] - 'a']++;
                if (hash[s2[i] - 'a'] == 0 && hash[s2[i - s1.size()] - 'a'] == 0 &&
                    qualify(hash)) {
                    return true;
                }
            }
        }
        return false;
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
    bool ans = Solution().checkInclusion(str, p);
    cout << ans;
    while (1);
}