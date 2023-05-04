//类似于双指针 模拟比较 相同就两个指针同时前进 不同就看typed指针有没有重复的字符可以跳过


#include <iostream>
#include <vector>

using namespace std;

 
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = 0;
        int t = 0;
        while (n < name.size() && t < typed.size()) {
            if (name[n] == typed[t]) {
                n++;
                t++;
            }
            else if (t > 0 && typed[t] == typed[t - 1]) {
                t++;
            }
            else {
                return false;
            }
        }
        while (t > 0 && t < typed.size()) {
            if (typed[t] == typed[t - 1]) {
                t++;
            }
            else {
                break;
            }
        }
        if (n < name.size() || t < typed.size()) {
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    bool ans = Solution().isLongPressedName(s, t);
    cout << ans;
    while (1);
}