//要考虑大数越界的问题 动态规划如果取余会有问题 只能考虑贪心算法 尽量多分段 每段长为三 如果剩下最后一段是1 就分成2 2 


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }
        int i = n / 3;
        int j = n % 3;
        unsigned int num = 1;
        if (j == 1) {
            i -= 1;
            num = 4;
        }
        else if (j == 0) {
            num = 1;
        }
        else {
            num = j;
        }
        while (i > 0) {
            num *= 3;
            num = num % 1000000007;
            i--;
        }
        return num;
    }
};

int main() {
    int n = 0;
    cin >> n;
    int ans = Solution().cuttingRope(n);
    cout << ans;
    while (1);
}