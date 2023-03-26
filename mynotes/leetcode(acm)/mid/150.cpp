//输入格式 第一行为字符串数组 中间用空格隔开 注意字符串和int之间的相互转换
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int num = 0;
        int ans = 0;
        for (string s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num2 = stoi(st.top());
                st.pop();
                int num1 = stoi(st.top());
                st.pop();
                if (s == "+") {
                    st.push(to_string(num1 + num2));//这里不用tostring 似乎也会自动转换
                }
                if (s == "-") {
                    st.push(to_string(num1 - num2));
                }
                if (s == "*") {
                    st.push(to_string(num1 * num2));
                }
                if (s == "/") {
                    st.push(to_string(num1 / num2));
                }
            }
            else {
                st.push(s);
            }
        }
        return stoi(st.top());
    }
};
int main() {
    string s;
    vector<string> strs;
    while (cin >> s) {
        strs.push_back(s);
    }
    cout << Solution().evalRPN(strs);
    while (1);
}