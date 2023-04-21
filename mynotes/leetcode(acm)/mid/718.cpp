//输入格式 第一行为数组1 数字间用空格隔开 第二行为数组2 数字间用空格隔开
//使用动态规划 这里有两个数组 需要一个二维dp数组 注意初始化 此题的子数组是指连续的子数组
//如果dp[i][j] 分别代表数组1下标为 i - 1 数组2下标为 j - 1 的数 就可以不初始化



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        int ans = 0;
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == nums1[0]) {
                dp[0][i] = 1;
                ans = 1;
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                ans = 1;
            }
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> nums1;
    while (cin >> num) {
        nums1.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    vector<int> nums2;
    while (cin >> num) {
        nums2.push_back(num);
    }
    int ans = Solution().findLength(nums1, nums2);
    cout << ans << endl;
    while (1);
}