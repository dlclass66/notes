//输入格式 数组 数字间用空格隔开
//直接的想法 用hash数组统计 最后再遍历hash数组得到没有出现过的
//因为nums数组长度正好为n所以也可以不使用额外空间（第二种方法） 

#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> hash(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]]++;
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = 1; i <= nums.size(); i++) {
            if (hash[i] == 0) {
                ans.push_back(i);
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
    vector<int> ans =  Solution().findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}



//不使用额外空间
//遍历到的nums[i] 如果大于0 就把对应的nums[nums[i] - 1]（如果大于0） 乘上-1 如果nums[i] 小于0 就操作nums[-nums[i] - 1]
//最后遍历 nums[i] 如果nums[i] 大于0 说明i + 1是消失的数字
#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                if (nums[-nums[i] - 1] > 0) {
                    nums[-nums[i] - 1] *= -1;
                }
            }
            else {
                if (nums[nums[i] - 1] > 0) {
                    nums[nums[i] - 1] *= -1;
                }
            }
        }
        vector<int> ans;
        ans.reserve(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
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
    vector<int> ans =  Solution().findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}