//输入格式 一行数组 数字间用空格隔开
//两次遍历 求出每一个柱子左右第一个小于的柱子的位置 算出此时的面积 最后再求出面积的最大值 比较冗余 但是逻辑比较简单 


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int size = heights.size();
        vector<int> s(size, 0);
        for (int i = 0; i < size; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                s[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            s[st.top()] = size;
            st.pop();
        }
        for (int i = size - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                s[st.top()] = (s[st.top()] - i - 1) * heights[st.top()];
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) {
            s[st.top()] = s[st.top()] * heights[st.top()];
            st.pop();
        }
        int ans = 0;
        for (int i : s) {
            ans = max(ans, i);
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
    int ans = Solution().largestRectangleArea(nums1);
    cout << ans << endl;
    while (1);
}