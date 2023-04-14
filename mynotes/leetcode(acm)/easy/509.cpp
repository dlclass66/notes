//输入数字n
//递归代码简单 也可以使用动态规划 效率更高


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }
};
int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().fib(2);
    cout << ans << endl;
    while (1);
}