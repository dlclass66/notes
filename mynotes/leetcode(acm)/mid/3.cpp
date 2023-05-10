//动态规划 时间复杂度较高 dp[i]表示以i结尾的字符串无重复的最大长度
//时间复杂度更优的方法是使用滑动窗口



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int ans = 1;
        vector<int> dp(s.size(), 1);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                dp[i] = 1;
                continue;
            }
            int j = dp[i - 1];
            int count = 1;
            int tempi = i - 1;
            while (j >= 1 && tempi >= 0) {
                if (s[i] == s[tempi]) {
                    break;
                }
                if (tempi == 0) {
                    count++;
                    break;
                }
                j = min(dp[tempi - 1], j - 1);
                tempi--;
                count++;
            }
            dp[i] = count;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};



int main() {
    string s;
    cin >> s;
    int ans = Solution().lengthOfLongestSubstring(s);
    cout << ans;
    while (1);
}


//滑动窗口 使用unordered_set 检查是否有重复的
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hash;
        int right = 0;
        int left = 0;
        int ans = 0;
        while (right < s.size()) {
            if (hash.find(s[right]) == hash.end()) {
                hash.insert(s[right]);
            }
            else {
                while (s[left] != s[right]) {
                    hash.erase(s[left]);
                    left++;
                }
                left++;
            }
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};



int main() {
    string s;
    cin >> s;
    int ans = Solution().lengthOfLongestSubstring(s);
    cout << ans;
    while (1);
}