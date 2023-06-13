//组合问题 可以cand数组的第0个开始 后续只能选下标更大的 这样就是组合而不是排列
//接下来的问题是去重 使用排序 每一位 相同的数字只选择一次



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    int sum = 0;
    vector<int> vec;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        help(candidates, target, 0);
        return ans;
    }

    void help(vector<int>& candidates, int target, int start) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (i == start || (i > start && candidates[i] != candidates[i - 1])) {
                sum += candidates[i];
                vec.push_back(candidates[i]);
                help(candidates, target, i + 1);
                sum -= candidates[i];
                vec.pop_back();
            }
        }
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int target = 0;
    cin >> target;
    vector<vector<int>> ans = Solution().combinationSum2(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    while (1);
}