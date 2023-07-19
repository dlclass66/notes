//使用动态规划 dp[i][j]表示以arr[j], arr[i]结尾的最长斐波那契数列长度
//用unordered_map存储arr中的元素到下标的映射



#include <vector>
#include <unordered_map>
#include <iostream>


using namespace std;

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int ans = 0;
        unordered_map<int, int> hash;
        for (int i = 0; i < arr.size(); i++) {
            hash[arr[i]] = i;
        }
        vector<vector<int>> dp(arr.size(),
            vector<int>(arr.size(), 2));
        dp[0][0] = 1;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] < arr[j] &&
                    hash.count(arr[i] - arr[j]) != 0) {
                    dp[i][j] = dp[j][hash[arr[i] - arr[j]]] + 1;
                    ans = max(ans, dp[i][j]);
                }
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
    int ans = Solution().lenLongestFibSubseq(nums);
    cout << ans;
    while (1);
}
