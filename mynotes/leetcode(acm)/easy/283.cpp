//不是很难 注意最后需要把剩下的变为0
//输入格式 直接输入数组 中间用空格隔开
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int fast, slow;
        fast = slow = 0;
        int count = 0;
        while (fast < nums.size()) {
            if (nums[fast] == 0) {
                fast++;
                count++;
            }
            else {
                nums[slow++] = nums[fast];
                fast++;
            }
        }
        for (int i = 0; i < count; i++) {
            nums[slow] = 0;
            slow++;
        }
    }
};
int main() {
    int num = 0;
    int target = 0;
    vector<int> myvec;
    while (cin >> num) {
        myvec.push_back(num);
        if (getchar() == '\n') {
            cin >> target;
            break;
        }
    }
    Solution().moveZeroes(myvec);
    for (int i = 0; i < myvec.size(); i++) {
        cout << myvec[i] << ' ';
    }
    while (1);
}