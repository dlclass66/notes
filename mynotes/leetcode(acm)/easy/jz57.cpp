//输入格式 第一行数组 第二行target
//可以用hash法 但是空间复杂度高 因为有序 可以用双指针 一个最左 一个最右


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                return { nums[left], target - nums[left] };
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return { -1, -1 };
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
    int target = 0;
    cin >> target;
    vector<int> ans = Solution().twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1];
    while (1);
}