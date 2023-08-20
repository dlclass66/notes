//使用单调栈，找到每个柱子左右两边第一个比它矮的柱子，然后计算面积 注意左右不是简单的reverse
//然后遍历 找到最大的面积



#include <iostream>
#include <vector>
#include <stack>


using namespace std;


class Solution {
public:
    vector<int> lower(vector<int>& heights, int flag) {
        stack<int> st;
        vector<int> ans(heights.size(), -1);
        if (flag == 0) {
            for (int i = 0; i < heights.size(); i++) {
                if (st.empty() || heights[st.top()] <= heights[i]) {
                    st.push(i);
                }
                else {
                    while (!st.empty() && heights[st.top()] > heights[i]) {
                        ans[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        else {
            for (int i = heights.size() - 1; i >= 0; i--) {
                if (st.empty() || heights[st.top()] <= heights[i]) {
                    st.push(i);
                }
                else {
                    while (!st.empty() && heights[st.top()] > heights[i]) {
                        ans[st.top()] = i;
                        st.pop();
                    }
                    st.push(i);
                }
            }
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> right_low = lower(heights, 0);
        vector<int> left_low = lower(heights, 1);
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            if (right_low[i] == -1) {
                right_low[i] = heights.size();
            }
            ans = max(ans, heights[i] * (right_low[i] - left_low[i] - 1));
        }
        return ans;
    }
};


int main() {
    int num = 0;
    vector<int> heights;
    while (cin >> num) {
		heights.push_back(num);
	}
    int ans = Solution().largestRectangleArea(heights);
    cout << ans;
    while (1);
}
