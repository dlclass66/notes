//输入格式 数组 数字间用空格隔开
//回溯 操作一定要撤销 每个数字只有放入和不放入两种情况



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> subsets(vector<int>& nums) {
        vec.reserve(nums.size());
        backtrack(nums, 0);
        return ans;
    }
    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                vec.push_back(nums[start]);
                backtrack(nums, start + 1);
                vec.pop_back();
            }
            else {
                backtrack(nums, start + 1);
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
    vector<vector<int>> ans = Solution().subsets(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}