//输入格式数组
//双指针 遇到奇偶错位就swap



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size()) {
            if (nums[left] % 2 == 0) {
                while (right < nums.size()) {
                    if (nums[right] % 2 == 1) {
                        swap(nums[left], nums[right]);
                        break;
                    }
                    right++;
                }
            }
            left++;
            right++;
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
    vector<int> ans = Solution().exchange(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}