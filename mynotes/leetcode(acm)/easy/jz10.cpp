//动态规划 可以不用数组 取余避免溢出

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int fib(int n) {
        int ans = 0;
        int pre1 = 1;
        int pre2 = 0;
        for (int i = 2; i <= n; i++) {
            int temp = pre1;
            pre1 = (pre1 + pre2) % 1000000007;
            pre2 = temp;
        }
        if (n == 0) {
            pre1 = 0;
        }
        ans = pre1 % 1000000007;
        return ans;
    }
};



int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().fib(num);
    cout << ans;
    while (1);
}