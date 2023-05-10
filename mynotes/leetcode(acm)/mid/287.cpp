//输入格式 数组 
//数组长度大于数字种类 所以可以用其自身当hash数组 nums[i] 就把nums[abs(nums[i]) - 1]变为相反数 如果已经是负的了 说明重复的就是abs（nums[i]）

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                if (nums[-nums[i] - 1] < 0) {
                    return -nums[i];
                }
                nums[-nums[i] - 1] *= -1;
            }
            else {
                if (nums[nums[i] - 1] < 0) {
                    return nums[i];
                }
                nums[nums[i] - 1] *= -1;
            }
        }
        return 0;
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans = Solution().findDuplicate(nums);
    cout << ans;
    while (1);
}