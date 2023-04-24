//回溯 使用used数组标记这个元素有没有使用过




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<int> used;
    vector<vector<int>> permute(vector<int>& nums) {
        vec.reserve(nums.size());
        used = vector<int>(21, 0);
        backtrack(nums, 0);
        return ans;
    }
    void backtrack(vector<int>& nums, int cur) {
        if (vec.size() == nums.size()) {
            ans.push_back(vec);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[nums[i] + 10] == 1) {
                continue;
            }
            vec.push_back(nums[i]);
            used[nums[i] + 10] = 1;
            backtrack(nums, cur + 1);
            vec.pop_back();
            used[nums[i] + 10] = 0;
        }
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<vector<int>> ans = Solution().permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}