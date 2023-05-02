//先遍历一遍得到所有数字的和
//再从左向右遍历 看有没有符合条件的
//输入格式 数组 数字间用空格隔开



#include <iostream>
#include <vector>

using namespace std;


 
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int ans = -1;
        for (int i : nums) {
            sum += i;
        }
        int target = sum;
        sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (2 * sum == target - nums[i]) {
                ans = i;
                break;
            }
            sum += nums[i];
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
    int ans = Solution().pivotIndex(nums);
    cout << ans;
    while (1);
}