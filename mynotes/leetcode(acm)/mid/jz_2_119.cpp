//最直接的想法是排序 
//因为进阶要求O(n)的时间复杂度，所以不能排序 可以使用unordered_map() 遍历nums[i] 判断其左右相邻的是否在hash中 把已经在的改为false 避免重复判断




#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = true;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash[nums[i]]) {
                int j = nums[i] + 1;
                while (j < nums[i] + (int)nums.size()) {
                    //上面要有（int） 否则会有问题
                    if (!hash[j]) {
                        break;
                    }
                    hash[j] = false;
                    j++;
                }
                int k = nums[i] - 1;
                while (k > nums[i] - (int)nums.size()) {
                    if (!hash[k]) {
                        break;
                    }
                    hash[k] = false;
                    k--;
                }
                ans = max(ans, j - k - 1);
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
    int ans = Solution().longestConsecutive(nums);
    cout << ans;
    while (1);
}