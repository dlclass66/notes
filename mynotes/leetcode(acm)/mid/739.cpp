//输入格式为数组 数字间用空格隔开
//最开始尝试使用pair 因为觉得需要保存序号和值 但是有数组 所以单调栈里面存序号即可

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = Solution().dailyTemperatures(nums);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}