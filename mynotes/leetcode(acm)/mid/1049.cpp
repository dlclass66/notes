//输入格式一行数组 数字间用空格隔开
//利用01背包 此题可转换为将石头分为两堆 求两堆差的最小值 则计算空间为sum / 2的背包最多价值即可 （这个就是总重量较小的石头堆的总重量）
//注意当使用一维dp数组时 应该从后往前遍历 因为要用到前面的数组


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i : stones) {
            sum += i;
        }
        vector<int> dp(sum / 2 + 1, 0);
        for (int i = 0; i < stones.size(); i++) {
            for (int j = sum / 2; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[sum / 2];
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().lastStoneWeightII(nums);
    cout << ans << endl;
    while (1);
}