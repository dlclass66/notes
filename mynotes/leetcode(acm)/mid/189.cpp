//输入格式 数组 数字间用空格隔开
//简单的想法是平移 因为存在覆盖的问题 所以用一个额外数组来存储
//不需要额外空间的方法见下文


#include <iostream>
#include <vector>

using namespace std;


 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) {
            return;
        }
        int start0 = 0;
        int start1 = k;
        vector<int> vec(nums.begin(), nums.begin() + k);
        while (start1 < k + nums.size()) {
            int temp = vec[start0 % k];
            vec[start0 % k] = nums[start1 % nums.size()];
            nums[start1 % nums.size()] = temp;
            start1++;
            start0++;
        }
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
    Solution().rotate(nums, k);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    while (1);
}



//无需额外空间的做法 类似左旋字符串 先reverse整个字符串 再旋转前k个 再旋转剩下的

#include <iostream>
#include <vector>

using namespace std;


 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
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
    Solution().rotate(nums, k);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    while (1);
}