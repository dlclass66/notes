//输入格式 第一行为数组 数字间用空格隔开
//分类处理即可 收到20时 首先尝试找零包含10


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for (int i : bills) {
            if (i == 5) {
                five++;
            }
            else if (i == 10) {
                five--;
                ten++;
                if (five < 0) {
                    return false;
                }
            }
            else {
                twenty++;
                if (ten > 0) {
                    ten--;
                    five--;
                }
                else {
                    five -= 3;
                }
                if (five < 0) {
                    return false;
                }
            }
        }
        return true;
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
    bool ans = Solution().lemonadeChange(nums);
    cout << ans << endl;
    while (1);
}