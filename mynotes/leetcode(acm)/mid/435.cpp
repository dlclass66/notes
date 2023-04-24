//输入格式 二维数组分行输入 每行数字用空格隔开
//跟射箭思路类似 每支箭射中的区间数减一就是这些区间中要删除的个数


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        struct cmp {
            bool operator() (vector<int>& i1, vector<int>& i2) {
                if (i1[0] == i2[0]) {
                    return i1[1] < i2[1];
                }
                else {
                    return i1[0] < i2[0];
                }
            }
        };
        sort(intervals.begin(), intervals.end(), cmp());
        int ans = 0;
        int count = 1;
        int right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < right) {
                right = min(intervals[i][1], right);
                count++;
            }
            else {
                right = intervals[i][1];
                ans += count - 1;
                count = 1;
            }
        }
        ans += count - 1;
        return ans;
    }
};
int main() {
    int num = 0;
    vector<vector<int>> nums;
    int i = 0;
    vector<int> temp(2, 0);
    while (cin >> num) {
        temp[i] = num;
        if (i == 1) {
            nums.push_back(temp);
            i = 0;
            continue;
        }
        i++;
    }
    int ans = Solution().eraseOverlapIntervals(nums);
    cout << ans;
    while (1);
}