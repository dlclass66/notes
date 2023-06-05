//注意所有项都是正数 但是有的取正号 有的负号 可以先求出都取正数的和 联立sum与target 得到取正数的和
//这样就可以转换为01背包问题 




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
        int new_target = sum + target;
        if (new_target % 2 == 1 || abs(target) > sum) {
            return 0;
        }
        new_target /= 2;
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
    cout << ans;
    while (1);
}