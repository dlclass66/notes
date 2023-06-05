//因为只买卖一次 所以记录最小值 如果当前价格小于最小值就更新 每天更新最大收益即可



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            }
            else {
                ans = max(prices[i] - min, ans);
            }
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> arr;
    while (cin >> num) {
        arr.push_back(num);
    }
    int ans = Solution().maxProfit(arr);
    cout << ans;
    while (1);
}