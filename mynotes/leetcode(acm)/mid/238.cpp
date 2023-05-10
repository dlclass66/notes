//输入格式数组
//遍历两遍 第一遍求左边的积 第二遍求左边积与右边积的积


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int count = 1;
        ans[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            ans[i] = count * nums[i - 1];
            count = ans[i];
        }
        count = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            ans[i] *= count * nums[i + 1];
            count *= nums[i + 1];
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
    vector<int> ans = Solution().productExceptSelf(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}