//回溯 需要同层去重 可以使用hash数组 也可以排序去重



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<int> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vec.reserve(nums.size());
        used = vector<int>(nums.size(), 0);
        backtrack(nums);
        return ans;
    }
    void backtrack(vector<int>& nums) {
        if (vec.size() == nums.size()) {
            ans.push_back(vec);
        }
        vector<int> used_this(21, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == 1 || used_this[nums[i] + 10] == 1) {
                continue;
            }
            vec.push_back(nums[i]);
            used[i] = 1;
            used_this[nums[i] + 10] = 1;
            backtrack(nums);
            vec.pop_back();
            used[i] = 0;
        }
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<vector<int>> ans = Solution().permuteUnique(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}