//为了使用位运算 需要都转换为绝对值 然后判断符号
//如果是INT_MIN转换为绝对值 使用int就存在越界问题 所以用unsigned int
//b 每次右移一位 直到大于等于a 然后再每次减去一个原来的b 直到小于等于a 




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int divide(int a, int b) {
        bool posa = true;
        bool posb = true;
        unsigned int tempa = 0;
        unsigned int tempb = 0;
        if (a < 0) {
            posa = false;
            if (a == INT_MIN) {
                tempa = (unsigned)INT_MAX + 1;
            }
            else {
                tempa = 0 - a;
            }
        }
        else {
            tempa = a;
        }
        if (b < 0) {
            posb = false;
            if (b == INT_MIN) {
                tempb = (unsigned)INT_MAX + 1;
            }
            else {
                tempb = 0 - b;
            }
        }
        else {
            tempb = b;
        }
        bool posi = false;
        if (posa && posb || !posa && !posb) {
            posi = true;
        }
        unsigned int tempans = 1;
        unsigned int temp = tempb;
        while (tempa > tempb) {
            tempb = tempb << 1;
            tempans = tempans << 1;
        }
        while (tempb > tempa) {
            tempb -= temp;
            tempans -= 1;
        }
        if (posi) {
            if (tempans > INT_MAX) {
                return INT_MAX;
            }
            return tempans;
        }
        else {
            return 0 - tempans;
        }
    }
};


int main() {
    int a;
    cin >> a;
    int b;
    cin >> b;
    int ans = Solution().divide(a, b);
    cout << ans;
    while (1);
}