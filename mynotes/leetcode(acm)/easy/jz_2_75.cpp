//使用计数排序 用一个hash数组 统计arr1中数字出现的次数 下标为数字 hash的元素为数量 
//遍历arr2 arr1从头开始根据hash表中的数量覆盖元素 最后再把arr2中没出现的按顺序覆盖到arr1中
//开始准备采用hash数组统计arr2中元素的出现位置 但是排序时如果使用标准库 无法调用之前的hash数组



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> hash(1001, 0);
        for (int i = 0; i < arr1.size(); i++) {
            hash[arr1[i]]++;
        }
        int i = 0;
        for (int j = 0; j < arr2.size(); j++) {
            while (hash[arr2[j]] > 0) {
                arr1[i] = arr2[j];
                hash[arr2[j]]--;
                i++;
            }
        }
        int j = 0;
        while (j < hash.size()) {
            while (hash[j] > 0) {
                arr1[i] = j;
                hash[j]--;
                i++;
            }
            j++;
        }
        return arr1;
    }
};

int main() {
    int num = 0;
    vector<int> nums1;
    while (cin >> num) {
        nums1.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    vector<int> nums2;
    while (cin >> num) {
        nums2.push_back(num);
    }
    vector<int> ans = Solution().relativeSortArray(nums1, nums2);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}