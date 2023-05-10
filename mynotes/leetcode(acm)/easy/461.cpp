//先异或让不同的位为1 再得到1的个数


#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    int hammingDistance(int x, int y) {
        int temp = x ^ y;
        return getbitcount(temp);
    }
    int getbitcount(int x) {
        int count = 0;
        while (x != 0) {
            x &= x - 1;
            count++;
        }
        return count;
    }
};


int main() {
    int num = 0;
    cin >> num;
    int y = 0;
    cin >> y;
    int ans =  Solution().hammingDistance(num, y);
    cout << ans;
    while (1);
}