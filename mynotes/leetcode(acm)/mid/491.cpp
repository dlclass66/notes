//回溯算法 注意去重逻辑 同层使用used数组（hash数组）


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    int count = 0;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vec.reserve(nums.size());
        backtrack(nums, 0);
        return ans;
    }
    void backtrack(vector<int>& nums, int start) {
        if (count >= 2) {
            ans.push_back(vec);
        }
        vector<int> used(201, 0);
        for (int i = start; i < nums.size(); i++) {
            if (vec.empty() || (!vec.empty() && nums[i] >= vec.back())) {
                if (used[nums[i] + 100] == 0) {
                    vec.push_back(nums[i]);
                    count++;
                    used[nums[i] + 100] = 1;
                    backtrack(nums, i + 1);
                    count--;
                    vec.pop_back();
                }
            }
        }
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<vector<int>> ans = Solution().findSubsequences(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}