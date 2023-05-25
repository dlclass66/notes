//全是正整数 可以使用滑动窗口 得到每个right对应的最远的left



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int product = 1;
        int ans = 0;
        int left = 0;
        int right = 0;
        if (k == 0 || k == 1) {
            return ans;
        }
        while (right < nums.size()) {
            if (product < k) {
                product *= nums[right];
                right++;
            }
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            ans += right - left;
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int k = 0;
    cin >> k;
    int ans = Solution().numSubarrayProductLessThanK(nums, k);
    cout << ans;
    while (1);
}