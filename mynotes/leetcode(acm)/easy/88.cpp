//输入格式 第一行是数组 数字间用空格隔开 第二行是m 第三行是数组 数字间用空格隔开 第四行是n
//从后往前填充 减少移动 注意最后如果是nums2还有剩余的情况 也要填充到nums1中
#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m + n - 1;
        int end1 = m - 1;
        int end2 = n - 1;
        while (end >= 0 && end1 >= 0 && end2 >= 0) {
            if (nums1[end1] < nums2[end2]) {
                nums1[end] = nums2[end2];
                end2--;
            }
            else {
                nums1[end] = nums1[end1];
                end1--;
            }
            end--;
        }
        if (end1 < 0) {
            while (end >= 0) {
                nums1[end] = nums2[end2];
                end2--;
                end--;
            }
        }
    }
};

int main() {
    vector<int> nums1;
    int num = 0;
    while (cin >> num) {
        nums1.push_back(num);
        if(getchar() == '\n')
			break;
    }
    int m = 0;
    cin >> m;
    vector<int> nums2;
    while (cin >> num) {
        nums2.push_back(num);
        if (getchar() == '\n')
            break;
    }
    int n = 0;
    cin >> n;
    nums1.resize(m + n);
    Solution().merge(nums1, m, nums2, n);
    for (int k : nums1) {
        cout << k << " ";
    }
    while(1);
}
