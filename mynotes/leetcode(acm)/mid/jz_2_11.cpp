//开始的想法是使用前缀表 然后两个for循环遍历 会超时 应该改用unordered_map 存储最早得到某个前缀和的位置 因为只需要最大的
//这样只需要循环一次就行了 但是要注意第一个可能不会命中 所以hash[0] = -1



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if (nums[0] == 1) {
            nums[0] = -1;
        }
        else {
            nums[0] = 1;
        }
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = nums[i - 1] + 1;
            }
            else {
                nums[i] = nums[i - 1] - 1;
            }
        }
        int ans = 0;
        unordered_map<int, int> hash;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                ans = max(ans, i - hash[nums[i]]);
            }
            else {
                hash[nums[i]] = i;
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
    int ans = Solution().findMaxLength(nums);
    cout << ans;
    while (1);
}