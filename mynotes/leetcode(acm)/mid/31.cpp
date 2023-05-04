//输入格式 数组 数字间用空格隔开
//下一个排列就是最后一个对数字 后面的比前面大 （靠前的为i， 靠后的为j） 对i+1到末尾进行排序
//如果找不到 则已经是最后一个排列了 反转数组即可
//这种方法找到的k其实就是i+1到结尾中比i大的之中最小的


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        reverse(nums.begin(), nums.end());
    }
};


int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    Solution().nextPermutation(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    while (1);
}