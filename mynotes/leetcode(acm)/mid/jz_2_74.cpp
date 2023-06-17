//先按左端点排序，然后遍历，如果当前区间的左端点小于等于上一个区间的右端点，说明有重叠，更新右端点，否则说明没有重叠，将上一个区间加入答案数组，然后更新区间为当前区间。


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        struct cmp {
            bool operator()(vector<int>& a, vector<int>& b) {
                return a[0] < b[0];
            }
        };
        sort(intervals.begin(), intervals.end(), cmp());
        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        int low = intervals[0][0];
        int high = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int temp0 = intervals[i][0];
            int temp1 = intervals[i][1];
            if (temp0 <= high) {
                high = max(high, temp1);
            }
            else {
                ans.push_back({ low, high });
                low = temp0;
                high = temp1;
            }
        }
        ans.push_back({ low, high });
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int>vec;
    vector<vector<int>> intervals;
    while (cin >> num) {
        vec.push_back(num);
        if (getchar() == '\n') {
            intervals.push_back(vec);
            vec.clear();
        }
    }
    intervals.push_back(vec);
    vector<vector<int>> ans = Solution().merge(intervals);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    while (1);
}