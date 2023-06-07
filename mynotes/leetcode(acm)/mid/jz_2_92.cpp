//先遍历一遍 用一个二维数组保存每个位置左边1的个数和右边0的个数
//然后遍历一遍 得到如果当前位置为分界点需要的反转次数
//ans初始值为全部反转为0 或 1之中较小的


#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> nums(s.size(), vector<int>(2, 0));
        int one = 0;
        int zero = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i][0] = one;
            nums[nums.size() - 1 - i][1] = zero;
            if (s[i] == '1') {
                one++;
            }
            if (s[s.size() - 1 - i] == '0') {
                zero++;
            }
        }
        int ans = min(zero, one);
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i][0] + nums[i][1];
            ans = min(ans, temp);
        }
        return ans;
    }
};

int main() {
    string text1;
    cin >> text1;
    int ans = Solution().minFlipsMonoIncr(text1);
    cout << ans;
    while (1);
}