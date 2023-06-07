//因为首位相连 所以分两种情况 1.不偷第一家 2.不偷最后一家 尾巴最后一个要特殊考虑
//不偷最后一家 就取偷到倒数第二家 偷不偷第一家的最大值 偷最后一家就不能偷倒数第二家和第一家
//注意只有一家的情况下可以偷



#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));
        dp[1][1] = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i - 1]);
        }
        dp[nums.size()][0] = max(dp[nums.size() - 1][1], max(dp[nums.size() - 1][0], dp[nums.size() - 2][0] + nums.back()));
        return dp.back()[0];
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
		nums.push_back(num);
	}
    int ans = Solution().rob(nums);
    cout << ans;
    while (1);
}