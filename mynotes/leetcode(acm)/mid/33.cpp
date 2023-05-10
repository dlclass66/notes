//输入格式数组 数字间用空格隔开
//直接的想法是先找到分割点再两个数组分别二分查找 
//


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                k = i;
                break;
            }
        }
        int left = findtarget(nums, 0, k - 1, target);
        int right = findtarget(nums, k, nums.size() - 1, target);
        if (left == -1) {
            return right;
        }
        else {
            return left;
        }
    }
    int findtarget(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return -1;
        }
        if (nums[left] > target || nums[right] < target) {
            return -1;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
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
    cin >> num;
    int ans = Solution().search(nums, num);
    cout << ans;
    while (1);
}