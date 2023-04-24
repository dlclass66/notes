//输入格式 二维数组 分行输入 每行的数组数字间用空格隔开
//先排序 然后重叠就更新右边的最大距离 不重叠就更新左右



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
        int left = intervals[0][0];
        int right = intervals[0][1];
        vector<vector<int>> ans;
        ans.reserve(intervals.size());
        vector<int> temp(2, 0);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > right) {
                temp[0] = left;
                temp[1] = right;
                ans.push_back(temp);
                left = intervals[i][0];
                right = intervals[i][1];
            }
            else {
                right = max(right, intervals[i][1]);
            }
        }
        temp[0] = left;
        temp[1] = right;
        ans.push_back(temp);
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> temp(2, 0);
    vector<vector<int>> nums;
    int i = 0;
    while (cin >> num) {
        temp[i] = num;
        if (i == 1) {
            nums.push_back(temp);
            i = 0;
            continue;
        }
        i++;
    }
    vector<vector<int>> ans = Solution().merge(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    while (1);
}