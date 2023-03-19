//不难 另一种方法是先算出整数平方根 再判断是不是完全平方
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }
        int left = 1;
        int right = num;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (num / mid == mid && num % mid == 0) { //注意这个条件
                return true;
            }
            if (num / mid > mid) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return false;
    }
};
int main() {
    int x = 0;
    cin >> x;
    bool ans = Solution().isPerfectSquare(x);
    cout << ans;
    while (1);
}