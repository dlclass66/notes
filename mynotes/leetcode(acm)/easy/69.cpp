//不难 但是需要转换思维
#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int left = 1;
        int right = x;
        while (left + 1 < right) {
            int mid = left + ((right - left) >> 1);
            if (x / mid == mid) {
                return mid;
            }
            if (x / mid > mid) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};
int main() {
    int x = 0;
    cin >> x;
    int ans = Solution().mySqrt(x);
    cout << ans;
    while (1);
}