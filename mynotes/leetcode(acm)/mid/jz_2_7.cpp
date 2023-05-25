//要去重 所以考虑排序然后去重 双指针（其实有三个）



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int k = 2;
        while (i < nums.size() - 2 && nums[i] <= 0) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            int sum = nums[i];
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    j++;
                    continue;
                }
                int temp = nums[j] + nums[k];
                if (temp + sum == 0) {
                    ans.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    k--;
                }
                else if (temp + sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
            i++;
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
    vector<vector<int>> ans = Solution().threeSum(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}