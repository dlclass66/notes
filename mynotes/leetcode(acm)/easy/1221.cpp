//从前向后遍历 遇到可以分割的就分割


#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int i = 0;
        int rcount = 0;
        int lcount = 0;
        while (i < s.size()) {
            if (s[i] == 'R') {
                rcount++;
            }
            else {
                lcount++;
            }
            if (rcount == lcount) {
                ans++;
                rcount = 0;
                lcount = 0;
            }
            i++;
        }
        return ans;
    }
};


int main() {
    string str;
    cin >> str;
    int ans = Solution().balancedStringSplit(str);
    cout << ans;
    while (1);
}