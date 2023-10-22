// 输入格式 数组 数字间用空格隔开
// 使用双指针 对于只允许重复出现k次的情况 如果nums[slow - k] == nums[fast] 说明已经重复k次了 慢指针无需操作 快指针继续向后
// 如果nums[slow - k] != nums[fast] 说明还没重复k次 快指针的值赋给慢指针 慢指针 快指针向后一位 
// 前k个元素一定是要保留的 所以slow从k开始

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int num : nums) {
            if (i < 2 || nums[i - 2] != num) {
                nums[i] = num;
                i++;
            }
        }
        return i;
    }
};

int main() {
    vector<int> nums;
    int num = 0;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n')
            break;
    }
    int ans = Solution().removeDuplicates(nums);
    for (int i = 0; i < ans; i++) {
        cout << nums[i] << " ";
    }
    while (1);
}
