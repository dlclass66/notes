//使用&&运算符的短路特性，当n>1时，执行sumNums(n-1) ，否则跳过。




#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ans = 0;
    int sumNums(int n) {
        bool x = n > 1 && sumNums(n - 1);
        ans += n;
        return ans;
    }
};

int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().sumNums(num);
    cout << ans;
    while (1);
}