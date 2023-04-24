//输入格式 第一行为数组 数字间用空格隔开 第二行为target
//可以无限制选取 注意递归条件 可以先排序然后剪枝


#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    int sum = 0;
    vector<int> vec;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.reserve(150);
        backtrace(candidates, target, 0);
        return ans;
    }
    void backtrace(vector<int>& cand, int target, int start) {
        if (sum == target) {
            ans.push_back(vec);
        }
        if (sum > target || target - sum == 1) {
            return;
        }
        for (int i = start; i < cand.size(); i++) {
            vec.push_back(cand[i]);
            sum += cand[i];
            backtrace(cand, target, i);
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
    vector<vector<int>> ans = Solution().combinationSum(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}