//使用滑动窗口加hash 




#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.size()) {
            if (hash.find(s[right]) == hash.end()) {
                hash.insert(s[right]);
                right++;
                ans = max(ans, right - left);
            }
            else {
                hash.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};

int main() {
    string str;
    cin >> str;
    int ans = Solution().lengthOfLongestSubstring(str);
    cout << ans;
    while (1);
}