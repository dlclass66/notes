//使用动态规划 dp[i]表示到达改行下标为i的最小路径和 



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back().size(), 0);
        dp[0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            dp[triangle[i].size() - 1] = dp[triangle[i - 1].size() - 1] +
                triangle[i].back();
            for (int j = triangle[i].size() - 2; j > 0; j--) {
                dp[j] = min(dp[j], dp[j - 1]) + triangle[i][j];
            }
            dp[0] = dp[0] + triangle[i][0];
        }
        int ans = dp[0];
        for (int i : dp) {
            ans = min(ans, i);
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> tri;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
			tri.push_back(nums);
			nums.clear();
		}
    }
    tri.push_back(nums);
    int ans = Solution().minimumTotal(tri);
    cout << ans;
    while (1);
}