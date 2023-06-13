//如果只有一个数字出现一次，其他数字都出现两次，那么可以用异或运算，因为相同数字异或为0，0与任何数字异或都是那个数字本身
//如果有两个数字出现一次，其他数字都出现两次，那么可以先对所有数字进行异或运算，得到的结果就是这两个数字的异或结果，然后找到这个结果中第一个为1的位，然后根据这个位将所有数字分为两组，这样两个数字就分别在两组中，然后对两组分别进行异或运算，就可以得到这两个数字
//注意&的优先级很低 需要（）


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int xornum = 0;
        for (int i = 0; i < nums.size(); i++) {
            xornum ^= nums[i];
        }
        int m = 1;
        while ((xornum & m) == 0) {
            m = m << 1;
        }
        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] & m) {
                x ^= nums[i];
            }
            else {
                y ^= nums[i];
            }
        }
        return { x, y };
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = Solution().singleNumbers(nums);
    cout << ans[0] << ' ' << ans[1];
    while (1);
}