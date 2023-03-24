//三数之和的扩展版 使用4个指针即可
//注意溢出 可以将一个转换为long
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        if (nums.size() < 4) {
            return ans;
        }
        int i = 0;
        while (i < nums.size() - 3) {
            if (nums[i] > target / 4) {
                break;
            }
            int numsi = nums[i];
            int j = i + 1;
            while (j < nums.size() - 2) {
                if ((target - nums[i]) / 3 < nums[j]) {
                    break;
                }
                int numsj = nums[j];
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    int numsleft = nums[left];
                    int numsright = nums[right];
                    if ((long)numsi + numsj + numsleft + numsright < target) { //不处理就会溢出
                        left++;
                    }
                    else if ((long)numsi + numsj + numsleft + numsright > target) {
                        right--;
                    }
                    else {
                        ans.push_back({ numsi, numsj, numsleft, numsright });
                        while (left < right && nums[left] == numsleft) {
                            left++;
                        }
                        while (left < right && nums[right] == numsright) {
                            right--;
                        }
                    }
                }
                while (j < nums.size() - 2 && nums[j] == numsj) {
                    j++;
                }
            }
            while (i < nums.size() - 3 && nums[i] == numsi) {
                i++;
            }
        }
        return ans;
    }
};
int main() {
    int num = 0;
    int target = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    cin >> target;
    vector<vector<int>> ans =  Solution().fourSum(nums, target);
    for (vector<int> vec : ans) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    while (1);
}