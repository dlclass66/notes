//输入格式 数组 数字间用空格隔开
//输出格式 便于演示 输出数组
//使用双指针 用fast找到下一个不同的数 用slow记录当前的位置

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] == nums[slow]) {
                fast++;
            }
            else {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
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
