//使用一个hash数组得到nums1数组值到序号的映射 nums2使用单调栈 弹出时检查是不是nums1中的 如果是就修改答案vector
//输入格式 每行一个数组 数字间用空格隔开
#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        int hash[10001];
        for (int i = 0; i < 10001; i++) {
            hash[i] = -1;
        }
        for (int i = 0; i < nums1.size(); i++) {
            hash[nums1[i]] = i;
        }
        stack<int> st;
        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                if (hash[st.top()] != -1) {
                    ans[hash[st.top()]] = nums2[i];
                }
                st.pop();
            }
            st.push(nums2[i]);
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> nums1;
    vector<int> nums2;
    while (cin >> num) {
        nums1.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    while (cin >> num) {
        nums2.push_back(num);
    }
    vector<int> ans = Solution().nextGreaterElement(nums1, nums2);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}