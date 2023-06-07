// 使用回溯算法，生成所有可能的括号组合，然后判断是否合法
//判断合法使用栈




#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;



class Solution {
public:
    int left = 0;
    int right = 0;
    string str;
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        help(n);
        return ans;
    }

    bool quailfy(string& str) {
        stack<int> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(') {
                st.push(0);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    void help(int n) {
        if (left > n || right > n || left + right > 2 * n) {
            return;
        }
        if (left == n && right == n) {
            if (quailfy(str)) {
                ans.push_back(str);
            }
            return;
        }
        left++;
        str.push_back('(');
        help(n);
        str.pop_back();
        left--;
        right++;
        str.push_back(')');
        help(n);
        str.pop_back();
        right--;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<string> ans = Solution().generateParenthesis(n);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    while (1);
}