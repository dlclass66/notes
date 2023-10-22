//输入格式 第一行为数组 数字间用空格隔开
//可以买卖多次 但是只能同时持有一支 上升就卖 再买入 下跌就更新买入价
//也可以使用动态规划



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > buy) {
                ans += prices[i] - buy;
                buy = prices[i];
            }
            else {
                buy = prices[i];
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
    int ans = Solution().maxProfit(nums);
    cout << ans << endl;
    while (1);
}