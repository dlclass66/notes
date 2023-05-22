//累加 先确定n所在的是几位数 然后确定具体是哪个数的第几位


#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        unsigned int i = 10;
        int j = 2;
        while (n - i >= 9 * pow(10, j - 1) * j) {
            i += 9 * pow(10, j - 1) * j;
            j++;
        }
        int count = 0;
        while (i <= n) {
            i += j;
            count++;
        }
        int num = pow(10, j - 1);
        num += count - 1;
        string str = to_string(num);
        return str[j - i + n] - '0';
    }
};

int main() {
    int n = 0;
    cin >> n;
    int ans = Solution().findNthDigit(n);
    cout << ans;
    while (1);
}