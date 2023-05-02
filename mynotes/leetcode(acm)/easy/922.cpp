//输入格式 数组 数字间用空格隔开
//类似双指针 一个指向奇数下标 一个指向偶数下标 如果两个正好反了就swap
//可以使用标准库的swap


#include <iostream>
#include <vector>

using namespace std;


 
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int num0 = 0;
        int num1 = 1;
        while (num0 < nums.size() && num1 < nums.size()) {
            if (nums[num0] % 2 == 1 && nums[num1] % 2 == 0) {
                swap(nums[num0], nums[num1]);
            }
            else if (nums[num0] % 2 == 0) {
                num0 += 2;
            }
            else if (nums[num1] % 2 == 1) {
                num1 += 2;
            }
        }
        return nums;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = Solution().sortArrayByParityII(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}