//最开始考虑排序 然后滑动窗口 但是未必连续 所以不行 然后考虑回溯 超时 
//应该使用01背包 注意遍历顺序 因为只有一维数组 为了不被覆盖 内层循环得倒着来
//判断大小为target的能不能得到target



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for (int i : nums) {
            target += i;
        }
        if (target % 2 == 1) {
            return false;
        }
        target /= 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
                if (dp[j] == target) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    bool ans = Solution().canPartition(nums);
    cout << ans;
    while (1);
}