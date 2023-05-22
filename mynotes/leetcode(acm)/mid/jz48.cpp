//滑动窗口 用一个unordered_set判断是否有重复的 没有就右指针++ 有的话就左指针++ 直到没有



#include <iostream>
#include <vector>
#include<unordered_set>

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