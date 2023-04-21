//输入格式 第一行为数组 数字间用空格隔开
//一个变量更新最小值 一个变量更新最大差值 如果使用动态规划 则每天对应两种情况 持有股票和不持有股票


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
                continue;
            }
            ans = max(ans, prices[i] - min);
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
    int ans = Solution().maxProfit(nums);
    cout << ans << endl;
    while (1);
}