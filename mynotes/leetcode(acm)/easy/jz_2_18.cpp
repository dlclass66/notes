//双指针 可以用tolower（）函数转化为小写


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char leftch = s[left];
            char rightch = s[right];
            bool leftchar = false;
            bool rightchar = false;
            bool leftnum = false;
            bool rightnum = false;
            if (leftch - 'a' < 26 && leftch - 'a' >= 0 ||
                leftch - 'A' < 26 && leftch - 'A' >= 0) {
                leftchar = true;
            }
            else if (leftch - '0' <= 9 && leftch - '0' >= 0) {
                leftnum = true;
            }
            if (rightch - 'a' < 26 && rightch - 'a' >= 0 ||
                rightch - 'A' < 26 && rightch - 'A' >= 0) {
                rightchar = true;
            }
            else if (rightch - '0' <= 9 && rightch - '0' >= 0) {
                rightnum = true;
            }
            if (leftchar && rightchar) {
                if (leftch != rightch && leftch - 'a' != rightch - 'A'
                    && leftch - 'A' != rightch - 'a') {
                    return false;
                }
                left++;
                right--;
            }
            else if (leftnum && rightnum) {
                if (leftch != rightch) {
                    return false;
                }
                left++;
                right--;
            }
            else if (leftchar) {
                if (rightnum) {
                    return false;
                }
                else {
                    right--;
                }
            }
            else if (rightchar) {
                if (leftnum) {
                    return false;
                }
                else {
                    left++;
                }
            }
            else if (leftnum) {
                right--;
            }
            else if (rightnum) {
                left++;
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};



int main() {
    string s;
    cin >> s;
    bool ans = Solution().isPalindrome(s);
    cout << ans;
    while (1);
}