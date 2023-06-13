//最直接的方法是用unordered_set
//可以用二进制 如果某一位的1的个数不是3的倍数 那么只出现一次的数字在这一位上是1 否则是0
//用一个数组保存每一位的1的个数 最后再还原即可




#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> vec(32, 0);
        for (int num : nums) {
            int i = 0;
            while (num != 0) {
                vec[i] += (num & 1);
                num = num >> 1;
                i++;
            }
        }
        int ans = 0;
        for (int i = vec.size() - 1; i >= 0; i--) {
            ans <<= 1;
            if (vec[i] % 3 == 1) {
                ans |= 1;
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
    int ans = Solution().singleNumber(nums);
    cout << ans;
    while (1);
}