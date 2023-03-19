//类似704 最后返回left或者right都可以 注意位运算 输入格式与704一致
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
int main() {
	int target = 0;
	vector<int> nums;
	int num;
	while (cin >> num) {
		nums.push_back(num);
		if (getchar() == '\n') {
			cin >> target;
			break;
		}
	}
    int ans = Solution().searchInsert(nums, target);
    cout << ans;
    while (1);
}