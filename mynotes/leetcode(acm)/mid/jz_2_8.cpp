//输入格式 第一行target 第二行数组 数字间用空格隔开
//因为全部是正整数 求最小连续 可以用滑动数组



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = nums.size();
        while (right <= nums.size()) {
            if (sum < target) {
                if (right == nums.size()) {
                    break;
                }
                sum += nums[right];
                right++;
            }
            else {
                while (sum >= target) {
                    sum -= nums[left];
                    left++;
                }
                ans = min(ans, right - left + 1);
            }
        }
        if (right == nums.size() && left == 0) {
            ans = 0;
        }
        return ans;
    }
};

int main() {
    int target = 0;
    cin >> target;
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().minSubArrayLen(target, nums);
    cout << ans;
    while (1);
}