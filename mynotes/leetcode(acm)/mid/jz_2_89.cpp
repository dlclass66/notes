//使用动态规划 dp[i] 表示 前i个房子能偷到的最大金额




#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++) {
            //有dp[i - 2]所以i从2开始
            //dp[i] 对应的是nums[i - 1]
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp.back();
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