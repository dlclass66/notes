//需要记录前面有发言机会的r和d议员个数（可用禁止数） 如果前面有敌对议员可以发言 当前议员就用另外的字符标记 表示禁止 更新可用禁止数
//如果一方议员个数变为0 则另一方获胜


#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    string predictPartyVictory(string senate) {
        int r = 0;
        int d = 0;
        while (true) {
            int rcount = 0;
            int dcount = 0;
            int i = 0;
            while (i < senate.size()) {
                if (r > 0 && senate[i] == 'D') {
                    senate[i] = 'a';
                    r--;
                }
                else if (senate[i] == 'D') {
                    d++;
                    dcount++;
                }
                else if (d > 0 && senate[i] == 'R') {
                    senate[i] = 'a';
                    d--;
                }
                else if (senate[i] == 'R') {
                    r++;
                    rcount++;
                }
                i++;
            }
            if (rcount == 0) {
                return "Dire";
            }
            else if (dcount == 0) {
                return "Radiant";
            }
        }

    }
};


int main() {
    string str;
    cin >> str;
    string ans = Solution().predictPartyVictory(str);
    cout << ans;
    while (1);
}