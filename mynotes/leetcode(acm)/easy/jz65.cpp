//模拟加法器 异或得到这一位加之后的值 &得到是否进位 因为进位关系到左边下一位 所以左移




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int c = (unsigned)(a & b) << 1;
            a = a ^ b;
            b = c;
        }
        return a;
    }
};



int main() {
    int a = 0;
    cin >> a;
    int b = 0;
    cin >> b;
    int ans = Solution().add(a, b);
    cout << ans;
    while (1);
}