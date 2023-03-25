//不是很难 输入格式 一行输入数组 中间用空格隔开
//双指针 也可以从两边向中间
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int fposi = 0;
        vector<int> myvec;
        while (fposi < nums.size() && nums[fposi] <= 0) {
            fposi++;
        }
        int right = fposi;
        int left = right - 1;
        while (left >= 0 && right < nums.size()) {
            if (nums[left] + nums[right] > 0) {
                myvec.push_back(nums[left] * nums[left]);
                left--;
            }
            else {
                myvec.push_back(nums[right] * nums[right]);
                right++;
            }
        }
        if (left < 0 && right >= nums.size()) {
            return myvec;
        }
        else if (left < 0) {
            while (right < nums.size()) {
                myvec.push_back(nums[right] * nums[right]);
                right++;
            }
        }
        else {
            while (left >= 0) {
                myvec.push_back(nums[left] * nums[left]);
                left--;
            }
        }
        return myvec;
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = Solution().sortedSquares(nums);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}

//第二种方法 注意需要倒着放 先放绝对值大的
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans(nums.size());
        int index = nums.size() - 1;
        while (left < right) {
            if (nums[left] + nums[right] > 0) {
                ans[index] = nums[right] * nums[right];
                right--;
                index--;
            }
            else {
                ans[index] = nums[left] * nums[left];
                left++;
                index--;
            }
        }
        ans[0] = nums[left] * nums[left];
        return ans;
    }
};