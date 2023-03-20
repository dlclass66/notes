//输入格式 第一行为查找的数组 数字用空格隔开 第二行为目标
//需要掌握up_bound的写法
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums, target);
        if (left == nums.size() || nums[left] != target) {
            return vector<int>({ -1, -1 });
        }
        int right = lower_bound(nums, target + 1) - 1;
        return vector<int>({ left, right });
    }
private:
    int lower_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= target) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
int main() {
    int num = 0;
    int target = 0;
    vector<int> myvec;
    while (cin >> num) {
        myvec.push_back(num);
        if (getchar() == '\n') {
            cin >> target;
            break;
        }
    }
    vector<int> ans = Solution().searchRange(myvec, target);
    cout << ans[0] << ' ' << ans[1];
    while (1);
}