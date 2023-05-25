//输入格式 第一行数组 第二行k
//开始的想法是 前缀和 然后两层遍历 会超时 
//优化思路是使用unorder_map 保存可以得到特定和的连续子数组数量 注意hash[0] 要初始化为1


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int ans = 0;
        int sum = 0;
        hash[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans += hash[sum - k];
            hash[sum]++;
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int k = 0;
    cin >> k;
    int ans = Solution().subarraySum(nums, k);
    cout << ans;
    while (1);
}