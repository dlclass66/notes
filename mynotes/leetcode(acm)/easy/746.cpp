//输入格式 数组 数字间用空格隔开
//使用动态规划即可 递推公式易得


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> cost_to(cost.size() + 1, 0);
        for (int i = 2; i < cost.size() + 1; i++) {
            cost_to[i] = min(cost_to[i - 1] + cost[i - 1],
                cost_to[i - 2] + cost[i - 2]);
        }
        return cost_to[cost.size()];
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num)
    {
        nums.push_back(num);
    }
    int ans = Solution().minCostClimbingStairs(nums);
    cout << ans << endl;
    while (1);
}