//有负数 一直右移并不会为0



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> dp(32, 0);
        for (int num : nums) {
            for (int i = 0; i < dp.size(); i++) {
                if (num >> i & 1) {
                    dp[i]++;
                }
            }
        }
        int ans = 0;
        for (int i = dp.size() - 1; i >= 0; i--) {
            ans = ans << 1;
            ans |= dp[i] % 3;
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
    int ans = Solution().singleNumber(nums);
    cout << ans;
    while (1);
}