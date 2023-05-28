//从小往大试 最开始的想法是直接遍历 会超时 然后改进是用位运算每次扩大两倍 
//因为有序 所以可以使用二分法


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int i = 1;
        while (i < x / 2) {
            if (x / i < i) {
                break;
            }
            i = i << 1;
        }
        while (i > 0) {
            if (x / i >= i) {
                return i;
            }
            i--;
        }
        return i;
    }
};

int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().mySqrt(num);
    cout << ans;
    while (1);
}



//二分法 因为要用除法比较是否符合题意（乘法可能会溢出）所以要注意除数为0的情况 


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) {
            return x;
        }
        if (x == 2 || x == 3) {
            return 1;
        }
        int left = 0;
        int right = x / 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (x / mid >= mid) {
                left = mid + 1;
                //必须加一 
            }
            else {
                right = mid - 1;
            }
        }
        return right;
        //因为left有加一 所以right是结果
    }
};

int main() {
    int num = 0;
    cin >> num;
    int ans = Solution().mySqrt(num);
    cout << ans;
    while (1);
}