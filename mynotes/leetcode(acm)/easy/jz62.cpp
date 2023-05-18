//直接模拟会超时 有数学解法 倒推
//最后还剩一个 编号为0 当剩两个时 删除的是编号为(m - 1) % i (i为剩余的个数) 这此时最后剩下的元素的下标为删除元素下标加一 （因为删除元素的下一个在下一轮为0） 




#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int lastRemaining(int n, int m) {
        int start = 0;
        for (int i = 2; i <= n; i++) {
            start = (m - 1) % i + start + 1;
            start = start % i;
        }
        return start;
    }
};



int main() {
    int n = 0;
    cin >> n;
    int m = 0;
    cin >> m;
    int ans = Solution().lastRemaining(n, m);
    cout << ans;
    while (1);
}