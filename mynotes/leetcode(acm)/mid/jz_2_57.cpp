//输入格式 第一行数组 第二行k 第三行t
//采用桶的思想 一个桶里面的元素差值不超过t 桶的大小为t+1 用一个unordered_map来存储桶的编号和元素值
//每个桶最多一个元素 所以用int到int的映射即可 每个数字检查其对应编号的桶和相邻的两个桶
//有溢出情况 要使用long 然后相当于滑动窗口 要注意移除超出距离的元素



#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int getid(int x, long t) {
        if (x >= 0) {
            x = x / (t + 1);
        }
        else {
            x = x / (t + 1) - 1;
        }
        return x;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> bucket;
        for (int i = 0; i < nums.size(); i++) {
            int id = 0;
            id = getid(nums[i], t);
            if (bucket.count(id)) {
                return true;
            }
            else if (bucket.count(id - 1) && (long)nums[i] - t <= bucket[id - 1]) {
                return true;
            }
            else if (bucket.count(id + 1) && (long)bucket[id + 1] - t <= nums[i]) {
                return true;
            }
            else {
                bucket[id] = nums[i];
                if (i >= k) {
                    bucket.erase(getid(nums[i - k], t));
                }
            }
        }
        return false;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if(getchar() == '\n')
			break;
    }
    int k = 0;
    cin >> k;
    int t = 0;
    cin >> t;
    bool ans = Solution().containsNearbyAlmostDuplicate(nums, k, t);
    cout << ans;
    while (1);
}