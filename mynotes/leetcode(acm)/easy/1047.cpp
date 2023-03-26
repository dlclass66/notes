//使用栈
//第二种方式直接将字符串当作栈
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty()) {
                st.push(ch);
            }
            else if (ch == st.top()) {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main() {
    string s;
    cin >> s;
    cout << Solution().removeDuplicates(s);
    while (1);
}

//第二种 注意字符串可以pop_back; 返回值也是void
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (char ch : s) {
            if (ans.size() == 0) {
                ans.push_back(ch);
            }
            else if (ch == *(ans.end() - 1)) {
                ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};