//输入格式 第一行为数组 数字间用空格隔开
//动态规划 因为首尾两间房不能同时偷 所以分为两种情况 不偷头 不偷尾 分别计算值 然后较大的就是所求的值
//可以使用首尾不相连的解法 包装成一个函数 



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp_notail(nums.size() - 1, 0);
        vector<int> dp_nohead(nums.size() - 1, 0);
        dp_nohead[0] = nums[1];
        dp_notail[0] = nums[0];
        dp_nohead[1] = max(nums[1], nums[2]);
        dp_notail[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; i++) {
            dp_nohead[i] = max(dp_nohead[i - 1],
                dp_nohead[i - 2] + nums[i + 1]);
            dp_notail[i] = max(dp_notail[i - 1],
                dp_notail[i - 2] + nums[i]);
        }
        return max(dp_notail[nums.size() - 2], dp_nohead[nums.size() - 2]);
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().rob(nums);
    cout << ans << endl;
    while (1);
}