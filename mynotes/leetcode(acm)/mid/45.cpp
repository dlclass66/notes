//输入格式 数组 数字间用空格隔开
//使用cover数组 循环得到每次能跳的最远距离 直到可以跳到最后一个位置
//需要记录当前能跳到的最远距离 和下一跳可以跳到的最远距离



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        int ans = 1;
        int cover = nums[0];
        int covernext = nums[0];
        int i = 0;
        while (covernext < nums.size() - 1) {
            cover = covernext;
            while (i <= cover) {
                covernext = max(covernext, i + nums[i]);
                if (covernext >= nums.size() - 1) {
                    break;
                }
                i++;
            }
            ans++;
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
    int ans = Solution().jump(nums);
    cout << ans << endl;
    while (1);
}