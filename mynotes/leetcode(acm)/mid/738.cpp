//使用to_string 将int转化为字符串 使用stoi将字符串转化为int
//从最后一位开始判断 先判断原数n是否符合条件 不符合就减小 仍然不符合说明应该减小前面的 这一位就为9



#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string nstr = to_string(n);
        if (rise(nstr)) {
            return n;
        }
        for (int i = nstr.size() - 1; i >= 0; i--) {
            if (nstr[i] == '0') {
                nstr[i] = '9';
                continue;
            }
            else {
                nstr[i]--;
                if (rise(nstr)) {
                    break;
                }
                else {
                    nstr[i] = '9';
                }
            }
        }
        return stoi(nstr);
    }
    bool rise(string& str) {
        for (int i = str.size() - 1; i > 0; i--) {
            if (str[i] < str[i - 1]) {
                return false;
            }
        }
        return true;
    }
};
int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().monotoneIncreasingDigits(num);
    cout << ans;
    while (1);
}