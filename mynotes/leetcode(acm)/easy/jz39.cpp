//可以排序也可以哈希表 排序时间复杂度高 哈希表空间复杂度高 用摩尔投票法
//摩尔投票法适合找出个数大于总数二分之一的数 如果没有 输出结果不确定
//假设第一个是答案 与答案相同vote++ 不相同vote-- vote小于等于0就重新选择答案 vote初始为1



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = nums[0];
        int vote = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == ans) {
                vote++;
            }
            else {
                vote--;
                if (vote <= 0) {
                    ans = nums[i + 1];
                    vote = 1;
                    i++;
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
    int ans = Solution().majorityElement(nums);
    cout << ans;
    while (1);
}