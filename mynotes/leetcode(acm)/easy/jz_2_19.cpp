//双指针 一个最左一个最右 往中间 因为只能最多去掉一位 所以第一次去掉左边的 第二次去掉右边的（遇到不相同的）有一次最终能变成回文串就说明可以

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        int count = 0;
        bool qualify = true;
        while (left < right) {
            if (s[left] != s[right]) {
                left++;
                count++;
                if (count >= 2) {
                    qualify = false;
                    break;
                }
            }
            else {
                left++;
                right--;
            }
        }
        if (qualify) {
            return true;
        }
        count = 0;
        qualify = true;
        left = 0;
        right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                right--;
                count++;
                if (count >= 2) {
                    qualify = false;
                    break;
                }
            }
            else {
                left++;
                right--;
            }
        }
        return qualify;
    }
};



int main() {
    string s;
    cin >> s;
    bool ans = Solution().validPalindrome(s);
    cout << ans;
    while (1);
}