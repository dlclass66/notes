//输入 一个数组
//最开始打算使用滑动窗口 但是动态规划更加简单 dp数组的含义就是以当前元素为结尾的子序列的最大和


#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i] + nums[i - 1]);
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};


int main() {
    vector<int> nums;
    int num = 0;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().maxSubArray(nums);
    cout << ans;
    while(1);
}
