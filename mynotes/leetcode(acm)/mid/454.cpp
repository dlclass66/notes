//输入格式 每一行为一个数组 数字之间用空格隔开
//应该使用unordered_map 而不是unordered_set 因为需要记录和为x的组合的个数
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hash;
        int count = 0;
        for (int i : nums1) {
            for (int k : nums2) {
                hash[i + k]++;
            }
        }
        for (int i : nums3) {
            for (int k : nums4) {
                if (hash.find(-i - k) != hash.end()) {
                    count += hash[-i - k];
                }
            }
        }
        return count;
    }
};
int main() {
    int num = 0;
    vector<int> nums1;
    vector<int> nums2;
    vector<int> nums3;
    vector<int> nums4;
    while (cin >> num) {
        nums1.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    while (cin >> num) {
        nums2.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    while (cin >> num) {
        nums3.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    while (cin >> num) {
        nums4.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    cout << Solution().fourSumCount(nums1, nums2, nums3, nums4);
    
    while (1);
}