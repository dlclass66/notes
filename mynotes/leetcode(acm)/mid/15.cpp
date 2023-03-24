//不要求返回下标 又需要去重 考虑排序
//输入格式 第一行为数组 数字间用空格隔开
//使用三个指针 最左边是i 中间是left 右边是right 大循环移动i
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < nums.size() - 2) {
            int left = i + 1;
            int right = nums.size() - 1;
            if (nums[i] > 0 || nums[right] < 0) {
                break;
            }//可以优化
            int numsi = nums[i];
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else {
                    int leftnum = nums[left];
                    int rightnum = nums[right];
                    ans.push_back({ nums[i], leftnum, rightnum });
                    while (left < right && nums[left] == leftnum) {
                        left++;
                    }
                    while (left < right && nums[right] == rightnum) {
                        right--;
                    }
                }
            }
            while (i < nums.size() - 2 && nums[i] == numsi) {
                i++;
            }
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
    
    vector<vector<int>> ans =  Solution().threeSum(nums);
    for (vector<int> vec : ans) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    while (1);
}