//输入格式第一行为字符串 使用push_back()方法
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        int i = 0;
        while (i < s.length()) {
            if (s[i] != ' ') {
                ans.push_back(s[i]);
            }
            else {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            i++;
        }
        return ans;
    }
};
int main() {
    string s;
    getline(cin, s);
    string ans = Solution().replaceSpace(s);
    cout << ans;
    while (1);
}

//第二种 只扩充一次s大小 使用双指针原地操作
class Solution {
public:
    string replaceSpace(string s) {
        int spacecount = 0;
        for (char i : s) {
            if (i == ' ') {
                spacecount++;
            }
        }
        s.resize(s.length() + 2 * spacecount);
        int slow = s.length() - 1;
        int fast = s.length() - 1;
        while (fast >= 0) {
            if (s[fast] == '\0') {
                fast--;
                continue;
            }
            if (s[fast] == ' ') {
                s[slow] = '0';
                s[slow - 1] = '2';
                s[slow - 2] = '%';
                slow -= 3;
            } else {
                s[slow] = s[fast];
                slow--;
            }
            fast--;
        }
        return s;
    }
};