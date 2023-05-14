//可以使用回溯 但是 滑动窗口效率更佳 如果sum == target 说明找到了 sum < target 说明 right要往右 否则说明left要往右




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        vector<int> nums(target / 2 + 1);
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = i + 1;
        }
        int left = 0;
        int right = 1;
        int count = nums[left];
        while (right < nums.size()) {
            count += nums[right];
            if (count == target) {
                ans.push_back(vector<int>(nums.begin() + left, nums.begin() + right + 1));
                right++;
            }
            else if (count < target) {
                right++;
            }
            else if (count > target) {
                while (count > target) {
                    count -= nums[left];
                    left++;
                }
                if (count == target) {
                    ans.push_back(vector<int>(nums.begin() + left, nums.begin() + right + 1));
                }
                right++;
            }
        }
        return ans;
    }
};



int main() {
    int target = 0;
    cin >> target;
    vector<vector<int>> ans = Solution().findContinuousSequence(target);
    for (vector<int>& i : ans) {
        for (int j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}