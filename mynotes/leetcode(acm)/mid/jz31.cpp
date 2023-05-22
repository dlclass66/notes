//双指针模拟栈 



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        while (j < pushed.size()) {
            while (i < pushed.size()) {
                if (pushed[i] == popped[j]) {
                    break;
                }
                i++;
            }
            if (i == pushed.size()) {
                return false;
            }
            pushed[i] = -1;
            if (i > 0) {
                //模拟弹出 遇到已经弹出的要跳过
                i--;
                while (i > 0 && pushed[i] == -1) {
                    i--;
                }
            }
            j++;
        }
        return true;
    }
};


int main() {
    int num = 0;
    vector<int> pushed;
    while (cin >> num) {
        pushed.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    vector<int> popped;
    while (cin >> num) {
        popped.push_back(num);
    }
    bool ans = Solution().validateStackSequences(pushed, popped);
    cout << ans;
    while (1);
}