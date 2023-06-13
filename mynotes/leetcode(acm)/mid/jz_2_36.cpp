//使用栈 遇到运算符号就弹出栈顶两个元素进行运算，然后将结果压入栈中，遇到数就入栈 最后栈中只剩下一个元素，就是结果




#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left + right);
            }
            else if (tokens[i] == "-") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left - right);
            }
            else if (tokens[i] == "*") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left * right);
            }
            else if (tokens[i] == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                st.push(left / right);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};



int main() {
    string str;
    vector<string> strs;
    while (cin >> str) {
        strs.push_back(str);
	}
    int ans = Solution().evalRPN(strs);
    cout << ans;
    
    while (1);
}