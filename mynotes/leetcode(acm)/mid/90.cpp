//输入格式 数组 数字间用空格隔开
//排序去重 



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vec.reserve(nums.size());
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
    void backtrack(vector<int>& nums, int start) {
        ans.push_back(vec);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            vec.push_back(nums[i]);
            backtrack(nums, i + 1);
            vec.pop_back();
        }
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<vector<int>> ans = Solution().subsetsWithDup(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}