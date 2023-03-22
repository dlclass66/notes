//输入格式第一行是数组1 数字之间用空格隔开 第二行是数组2
//使用hash数组
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        array<int, 1001> hash{ 0 };
        for (int i : nums1) {
            hash[i]++;
        }
        for (int i : nums2) {
            if (hash[i] != 0) {
                ans.push_back(i);
                hash[i] = 0;
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums1;
    vector<int> nums2;
    int num = 0;
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
    vector<int> ans = Solution().intersection(nums1, nums2);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}