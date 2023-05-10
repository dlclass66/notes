//输入格式 数组
//第一种方法是排序 比较直接 但是复杂度超过题目要求

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int ans = 1;
        int count = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                count++;
                ans = max(count, ans);
                continue;
            }
            if (nums[i] == nums[i - 1]) {
                continue;
            }
            count = 1;
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

//第二种方法是使用unordered_set 如果nums[i]在set中 就拿出来 然后左右遍历 看是否也在set中 在就拿出来 


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> hash(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end()) {
                hash.erase(nums[i]);
                int left = 0;
                while (hash.find(nums[i] - left - 1) != hash.end()) {
                    left++;
                    hash.erase(nums[i] - left);
                }
                int right = 0;
                while (hash.find(nums[i] + right + 1) != hash.end()) {
                    right++;
                    hash.erase(nums[i] + right);
                }
                ans = max(ans, 1 + left + right);
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