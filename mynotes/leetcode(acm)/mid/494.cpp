//输入格式 第一行为数组 数字间用空格隔开 第二行为target
//使用01背包 这个题需要的是方法的个数而不是最值 所以dp数组的含义需要改变 变为装满容量为j的背包的方法数 有两种可能得到 一种是不装i 一种是装i 所以是累加 每次加上装i 注意对dp[0]的初始


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (abs(target) > sum || (target + sum) % 2 == 1) {
            return 0;
        }
        int new_target = (target + sum) / 2;
        vector<int> dp(new_target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = new_target; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[new_target];
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
    int ans = Solution().findTargetSumWays(nums, target);
    cout << ans << endl;
    while (1);
}