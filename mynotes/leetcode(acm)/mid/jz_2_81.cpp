//如果只是求组合个数 可以用背包 需要得到具体的组合方式 采用回溯
//因为每个数字可以重复使用 所以每次递归的时候从当前数字开始



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        help(candidates, target, 0);
        return ans;
    }

    void help(vector<int>& candidates, int target, int start) {
        if (sum >= target) {
            if (sum == target) {
                ans.push_back(vec);
            }
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            sum += candidates[i];
            vec.push_back(candidates[i]);
            help(candidates, target, i);
            sum -= candidates[i];
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
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    while (1);
}