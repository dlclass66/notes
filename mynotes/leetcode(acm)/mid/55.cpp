//输入格式 第一行为数组 数字间用空格隔开
//倒序遍历 能跳到就更新目标 判断最后目标能不能更新到0
//也可以正序遍历 更新每次能覆盖到的最远距离


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target = nums.size() - 1;
        int i = nums.size() - 2;
        while (i >= 0) {
            if (i + nums[i] >= target) {
                target = i;
                i--;
            }
            else {
                i--;
            }
        }
        return target == 0;
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    bool ans = Solution().canJump(nums);
    cout << ans << endl;
    while (1);
}