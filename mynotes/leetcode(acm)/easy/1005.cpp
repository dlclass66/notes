//输入格式 第一行为数组 数字间用空格隔开 第二行为k
//贪心 先排序 尽量翻转负数 如果如果k还有剩余就翻转绝对值最小的



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int ans = 0;
        while (k > 0) {
            if (i >= nums.size()) {
                i--;
                k++;
                break;
            }
            if (nums[i] > 0) {
                if (i > 0 && nums[i] + nums[i - 1] > 0) {
                    i = i - 1;
                    k++;
                }
                break;
            }
            i++;
            k--;
        }
        for (int j = 0; j < nums.size(); j++) {
            if (j < i) {
                ans += -nums[j];
            }
            else if (j == i) {
                continue;
            }
            else {
                ans += nums[j];
            }
        }
        if (k % 2 == 1) {
            nums[i] *= -1;
        }
        return ans + nums[i];
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
    int k = 0;
    cin >> k;
    int ans = Solution().largestSumAfterKNegations(nums, k);
    cout << ans << endl;
    while (1);
}