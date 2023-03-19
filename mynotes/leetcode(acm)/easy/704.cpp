//二分查找 输入示例
//-1 0 3 5 9 12
//9
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0; //左闭右开
        int end = nums.size();
        int mid = 0;
        while (start < end) {
            mid = (start + (end - start) / 2);
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return -1;
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
    int ans = Solution().search(nums, target);
    cout << ans;
    while (1);
}