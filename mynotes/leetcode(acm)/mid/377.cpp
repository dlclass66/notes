//输入格式 第一行为数组 数字间用空格隔开 第二行为target
//完全背包 因为一个数可以被放入任意次 但是注意顺序不同被记为不同 所以外层循环是背包容量 里层是序号 注意题目中说明是32位整数 所以方法数使用unsigned int


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i < nums[j]) {
                    continue;
                }
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
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
    unsigned int ans = Solution().combinationSum4(nums, target);
    cout << ans << endl;
    while (1);
}