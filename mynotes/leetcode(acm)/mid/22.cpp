//回溯算法 加上一定的剪枝


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<string> ans;
    string str;
    int leftnum = 0;
    int rightnum = 0;
    vector<string> generateParenthesis(int n) {
        help(0, n, 0);
        return ans;
    }
    void help(int idx, int n, int left) {
        if (idx >= 2 * n) {
            return;
        }
        if (left < 0) {
            return;
        }
        if (leftnum > n || rightnum > n) {
            return;
        }
        if (idx == 2 * n - 1) {
            if (left == 1) {
                ans.push_back(str);
                ans.back().push_back(')');
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                str.push_back('(');
                leftnum++;
                help(idx + 1, n, leftnum - rightnum);
                str.pop_back();
                leftnum--;
            }
            else {
                str.push_back(')');
                rightnum++;
                help(idx + 1, n, leftnum - rightnum);
                str.pop_back();
                rightnum--;
            }
        }
    }
};



int main() {
    int num = 0;
    cin >> num;
    vector<string> ans = Solution().generateParenthesis(num);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}