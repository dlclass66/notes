//输入格式 第一行数组 数字用空格隔开 第二行target
//滑动窗口用嵌套循环比较好写 
//复杂度为n 每个循环操作一个数 一个数最多被加一次 减一次
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minlength = nums.size() + 1;
        for (; right < nums.size(); right++) {
            sum += nums[right];
            if (sum < target) {
                continue;
            }
            while (sum >= target) {
                sum -= nums[left];
                left++;
            }
            sum += nums[--left];
            if (right - left + 1 < minlength) {
                minlength = right - left + 1;
            }
        }
        if (minlength == nums.size() + 1) {
            return 0;
        }
        else {
            return minlength;
        }
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    int target = 0;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            cin >> target;
        }
    }
    int ans = Solution().minSubArrayLen(target, nums);
    cout << ans;
    while (1);
}