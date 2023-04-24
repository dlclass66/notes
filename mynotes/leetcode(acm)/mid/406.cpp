//输入格式 二维数组分行输入 每行的数字用空格隔开
//首先将people进行排序 身高高的在前 身高相同的ki小的在前 然后遍历people 插入位置为begin + ki（因为身高大于等于的都已经在数组中了）
//因为要频繁的插入 所以可以考虑使用list 最后再把结果放入vector中


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        struct cmp {
            bool operator()(vector<int>& p1, vector<int>& p2) {
                if (p1[0] == p2[0]) {
                    return p1[1] < p2[1];
                }
                else {
                    return p1[0] > p2[0];
                }
            }
        };
        sort(people.begin(), people.end(), cmp());
        vector<vector<int>> ans;
        ans.reserve(people.size());
        for (int i = 0; i < people.size(); i++) {
            int temp = people[i][1];
            ans.insert(ans.begin() + temp, people[i]);
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
    vector<vector<int>> ans = Solution().reconstructQueue(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
    while (1);
}