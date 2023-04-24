//输入格式 第一行数组 数字间用空格隔开 第二行target
//回溯算法 注意去重的逻辑 排序剪枝



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    int sum = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vec.reserve(candidates.size());
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
    void backtrack(vector<int>& cand, int target, int start) {
        if (sum == target) {
            ans.push_back(vec);
        }
        for (int i = start; i < cand.size(); i++) {
            if (sum + cand[i] > target) {
                break;
            }
            if (i > start && cand[i] == cand[i - 1]) {
                continue;
            }
            sum += cand[i];
            vec.push_back(cand[i]);
            backtrack(cand, target, i + 1);
            sum -= cand[i];
            vec.pop_back();
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
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}