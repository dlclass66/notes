//括号匹配可以使用栈 容易得到能够匹配上的位置对 存储在一个数组中 主要问题是相邻的但并不包含的括号对 （被包含的括号对总是比外层的括号对先出现）
//所以虫后往前遍历 如果当前括号对已经被包含就跳过 如果是相邻就扩展left right 如果不相邻就重置left right



#include <iostream>
#include <vector>
#include <stack>

using namespace std;



class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        vector<int> qualify;
        qualify.reserve(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(i);
            }
            else {
                int j = st.top();
                if (s[j] == '(' && s[i] == ')') {
                    qualify.push_back(j);
                    qualify.push_back(i);
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
        }
        int ans = 0;
        int left = 0;
        int right = 0;
        if (qualify.empty()) {
            return 0;
        }
        for (int i = qualify.size() - 2; i >= 0; i -= 2) {
            if (left < qualify[i] && right > qualify[i + 1]) {
                continue;
            }
            if (qualify[i + 1] + 1 == left) {
                left = qualify[i];
            }
            else {
                left = qualify[i];
                right = qualify[i + 1];
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};



int main() {
    string str;
    cin >> str;
    int ans = Solution().longestValidParentheses(str);
    cout << ans;
    while (1);
}