//使用二分查找 通过判断左右的长度判断落单的数在左边还是右边


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > 0) {
                if (nums[mid] == nums[mid - 1]) {
                    if (mid % 2 == 0) {
                        right = mid - 2;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    if (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]) {
                        return nums[mid];
                    }
                    else {
                        if (mid % 2 == 0) {
                            left = mid + 2;
                        }
                        else {
                            right = mid - 1;
                        }
                    }
                }
            }
            else {
                if (nums[mid] != nums[mid + 1]) {
                    return nums[mid];
                }
                else {
                    left = mid + 2;
                }
            }
        }
        return nums[left];
    }
};

int main() {
    int num = 0;
    vector<int>vec;
    while (cin >> num) {
        vec.push_back(num);
    }
    int ans = Solution().singleNonDuplicate(vec);
    cout << ans << endl;
    while (1);
}