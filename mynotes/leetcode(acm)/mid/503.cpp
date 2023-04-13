//输入格式 第一行为数组 中间用空格隔开
//最开始扩充了数组 但是其实不用 用求余多循环一遍即可


#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        stack<int> st;
        for (int i = 0; i < nums.size() * 2; i++) {
            while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                ans[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            if (i < nums.size()) {
                st.push(i);
            }
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
    vector<int> ans = Solution().nextGreaterElements(nums1);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}