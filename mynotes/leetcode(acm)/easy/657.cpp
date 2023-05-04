//一步一步走 看最后坐标是不是（0，0）即可

#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'R') {
                x++;
            }
            if (moves[i] == 'L') {
                x--;
            }
            if (moves[i] == 'U') {
                y++;
            }
            if (moves[i] == 'D') {
                y--;
            }
        }
        return x == 0 && y == 0;
    }
};


int main() {
    string str;
    cin >> str;
    bool ans =  Solution().judgeCircle(str);
    cout << ans;
    while (1);
}