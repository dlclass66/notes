//输入格式 第一行数组 第二行target
//转化为lower_bound即可 注意标准库的lower_bound返回值是迭代器



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int b = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        return b - a;
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
    int target = 0;
    cin >> target;
    int ans = Solution().search(nums, target);
    cout << ans;
    while (1);
}



//自己实现lower_bound的版本

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int a = lowerbound(nums, target);
        int b = lowerbound(nums, target + 1);
        return b - a;        
    }
    int lowerbound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};  