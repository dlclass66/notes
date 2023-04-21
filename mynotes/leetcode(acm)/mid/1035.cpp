//输入格式 第一行为第一个数组 数字间用空格隔开 第二行为第二个数组 数字间用空格隔开
//就是求最长公共子序列 这里的子序列不要求连续



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
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
    int ans = Solution().maxUncrossedLines(nums1, nums2);
    cout << ans << endl;
    while (1);
}