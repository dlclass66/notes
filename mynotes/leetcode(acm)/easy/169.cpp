//输入 数组 数字间用空格隔开
//采用摩尔投票法 如果当前数字与当前众数相同则计数器加一 否则减一 当计数器为0时更换众数


#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == ans) {
                count++;
            }
            else {
                count--;
                if (count <= 0) {
                    ans = nums[i];
                    count = 1;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums;
    int num = 0;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n')
            break;
    }
    int ans = Solution().majorityElement(nums);
    cout << ans;
    while (1);
}
