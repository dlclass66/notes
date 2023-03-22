//输入格式 第一行输入数组 数字中间用空格隔开 第二行为target
//可以使用unordered_set 注意题目要求是返回索引而不是值
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_set<int> hash;
        int pos1 = 0;
        int pos2 = 0;
        int num1 = 0;
        int num2 = 0;
        for (int i : nums) {
            if (hash.find(target - i) != hash.end()) {
                num1 = i;
                num2 = target - i;
                break;
            }
            hash.insert(i);
            pos1++;
        }
        for (int i : nums) {
            if (i == num2) {
                break;
            }
            pos2++;
        }
        ans.push_back(pos1);
        ans.push_back(pos2);
        return ans;
    }
};
int main() {
    int target = 0;
    int num = 0;
    vector<int> nums;
    vector<int> ans;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    cin >> target;
    ans = Solution().twoSum(nums, target);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}