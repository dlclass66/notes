//使用快排 手写一个实现 核心是先选一个哨兵 通常是第一个数 把大于的都移到这个数右边 小于的移到左边 相等的两边都可以 然后递归左右两个子问题



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        quicksort(arr, 0, arr.size() - 1);
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
    void quicksort(vector<int>& vec, int start, int end) {
        if (start >= end) {
            return;
        }
        int target = vec[start];
        int left = start;
        int right = end;
        while (left < right) {
            while (left < right) {
                if (vec[right] < target) {
                    break;
                }
                right--;
            }
            while (left < right) {
                if (vec[left] > target) {
                    break;
                }
                left++;
            }
            if (left < right) {
                swap(vec[left], vec[right]);
            }
            else {
                break;
            }
        }
        swap(vec[left], vec[start]);
        quicksort(vec, start, left - 1);
        quicksort(vec, left + 1, end);
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
    vector<int> ans = Solution().getLeastNumbers(nums, target);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}