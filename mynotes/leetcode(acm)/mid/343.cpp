//使用动态规划 对应数组表示n拆分最大的乘积 有3种拆分方式 拆成两个 拆成一个和多个 拆成多个和一个 后两种有重复 


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        vector<int> power(n + 1, 0);
        power[2] = 1;
        power[1] = 1;
        for (int i = 3; i < n + 1; i++) {
            for (int j = 1; j < i; j++) {
                power[i] = max(power[i], power[j] * power[i - j]);
                power[i] = max(power[i], j * power[i - j]);
                power[i] = max(power[i], j * (i - j));
            }
        }
        return power[n];
    }
};
int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().integerBreak(num);
    cout << ans << endl;
    while (1);
}