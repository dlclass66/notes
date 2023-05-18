//



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        bool neg = false;
        bool i_min = false;
        if (n < 0) {
            neg = true;
            if (n == INT_MIN) {
                i_min = true;
                n = INT_MAX;
            }
            else {
                n = 0 - n;
            }
        }
        vector<int> pos;
        pos.reserve(32);
        int count = 0;
        while (n > 0) {
            if (n & 1 == 1) {
                pos.push_back(count);
            }
            count++;
            n = n >> 1;
        }
        double ans = 1;
        double temp = x;
        int i = 0;
        int j = 0;
        while (i <= pos.back()) {
            if (i == pos[j]) {
                ans *= temp;
                j++;
            }
            temp *= temp;
            i++;
        }

        if (i_min) {
            ans *= x;
        }
        if (neg) {
            ans = 1.0 / ans;
        }
        return ans;
    }
};


int main() {
    double x = 0;
    cin >> x;
    int n = 0;
    cin >> n;
    double ans = Solution().myPow(x, n);
    cout << ans;
    while (1);
}