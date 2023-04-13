//输入格式为一行数组 数字中间用空格隔开
//找出右边第一个更高（或者相等）的 中间矮的不入栈 求之间的积水 最后还需要从右往左 求到最高的为止 


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        stack<int> st;
        int sum = 0;
        for (int i = 0; i < height.size(); i++) {
            if (!st.empty() && height[i] < height[st.top()]) {
                sum += height[i];
                continue;
            }
            if (!st.empty() && height[i] >= height[st.top()]) {
                ans += (i - st.top() - 1) * height[st.top()] - sum;
                st.pop();
                sum = 0;
            }
            st.push(i);
        }
        sum = 0;
        int maxnum = st.top();
        st.pop();
        for (int i = height.size() - 1; i >= maxnum; i--) {
            if (!st.empty() && height[i] < height[st.top()]) {
                sum += height[i];
                continue;
            }
            if (!st.empty() && height[i] >= height[st.top()]) {
                ans += (st.top() - i - 1) * height[st.top()] - sum;
                st.pop();
                sum = 0;
            }
            st.push(i);
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> nums1;
    while (cin >> num) {
        nums1.push_back(num);
    }
    int ans = Solution().trap(nums1);
    cout << ans << endl;
    while (1);
}