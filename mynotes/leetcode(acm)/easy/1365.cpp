//输入格式 数组 数字间用空格隔开
//排序 然后使用unordered_map映射 因为输出的数组的顺序是排序前的顺序 也可以使用hash数组 从后向前遍历



#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


 
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        unordered_map<int, vector<int>> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
        }
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = 0; j < hash[nums[i]].size(); j++) {
                ans[hash[nums[i]][j]] = i;
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
    vector<int> ans = Solution().smallerNumbersThanCurrent(nums);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}