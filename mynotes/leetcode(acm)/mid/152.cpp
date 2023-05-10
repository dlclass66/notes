//输入格式 数组 
//第一种方法得到每段乘积 求最大的 时间复杂度较高


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, nums[i]);
            for (int j = i + 1; j < nums.size(); j++) {
                if (j == i + 1) {
                    pre = nums[i] * nums[j];
                }
                else {
                    pre *= nums[j];
                }
                ans = max(ans, pre);
            }
        }
        return ans;
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().maxProduct(nums);
    cout << ans;
    while (1);
}

//第二种方法 动态规划 使用二维数组dp 因为有正有负 所以dp[i][0] 表示以i结尾的最小乘积 dp[i][1]表示以i结尾的最大乘积 


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        for (int i = 0; i < nums.size(); i++) {
            dp[i][0] = nums[i];
            dp[i][1] = nums[i];
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {

            }
            else if (nums[i] > 0) {
                dp[i][1] = max(nums[i], dp[i - 1][1] * nums[i]);
                dp[i][0] = min(nums[i], dp[i - 1][0] * nums[i]);
            }
            else {
                dp[i][1] = max(nums[i], dp[i - 1][0] * nums[i]);
                dp[i][0] = min(nums[i], dp[i - 1][1] * nums[i]);
            }
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().maxProduct(nums);
    cout << ans;
    while (1);
}