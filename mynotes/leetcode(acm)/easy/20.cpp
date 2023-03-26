//使用标准容器stack即可
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if (st.empty()) {
                    return false;
                }
                if (ch == ')' && st.top() == '(') {
                    st.pop();
                }
                else if (ch == '}' && st.top() == '{') {
                    st.pop();
                }
                else if (ch == ']' && st.top() == '[') {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return (st.empty());
    }
};              
int main() {
    string s;
    cin >> s;
    cout << Solution().isValid(s);
    while (1);
}