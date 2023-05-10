//动态规划 中途取余避免溢出


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int numWays(int n) {
        int pre1 = 1;
        int pre2 = 1;
        for (int i = 2; i <= n; i++) {
            int temp = pre1;
            pre1 = (pre1 + pre2) % 1000000007;
            pre2 = temp;
        }
        return pre1;
    }
};



int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().numWays(num);
    cout << ans;
    while (1);
}