//输入格式 数组 数字间用空格隔开
//简单的想法是用hash表 但是这样空间不是常量
//复杂的想法是用异或 因为除了一个数字之外都是2个


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i : nums) {
            hash[i]++;
        }
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if ((*it).second == 1) {
                return (*it).first;
            }
        }
        return 0;
    }
};


int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int ans =  Solution().singleNumber(nums);
    cout << ans;
    while (1);
}

//使用异或的版本

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            ans ^= nums[i];
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
    int ans =  Solution().singleNumber(nums);
    cout << ans;
    while (1);
}