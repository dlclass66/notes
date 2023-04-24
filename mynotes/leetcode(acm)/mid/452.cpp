//输入格式 二维数组分行输入 每行的数字间用空格隔开
//因为有重叠的气球可以一起射 先对points进行排序 把可能重叠的排在一起 然后遍历points数组
//左边界小于等于当前最小右边界的就可以一起射 再更新当前最小右边界 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        struct cmp {
            bool operator()(vector<int>& p1, vector<int>& p2) {
                if (p1[0] == p2[0]) {
                    return p1[1] < p2[1];
                }
                else {
                    return p1[0] < p2[0];
                }
            }
        };
        sort(points.begin(), points.end(), cmp());
        int left = points[0][0];
        int right = points[0][1];
        int ans = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= right) {
                right = min(points[i][1], right);
            }
            else {
                ans++;
                right = points[i][1];
            }
        }
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
    int ans = Solution().findMinArrowShots(nums);
    cout << ans;
    while (1);
}