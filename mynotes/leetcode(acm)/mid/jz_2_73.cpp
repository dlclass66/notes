//最开始的想法是先计算出最小的可能的速度 然后逐步递增 找到最小允许速度 会超时
//因为是顺序序列 考虑二分法 




#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0;
        int high = 0;
        for (int i : piles) {
            low += i / h;
            high = max(high, i);
        }
        if (low == 0) {
            low++;
        }
        while (low <= high) {
            int hour = 0;
            int mid = (low + (high - low) / 2);
            for (int i : piles) {
                hour += i / mid + 1;
                if (i % mid == 0) {
                    hour--;
                }
                if (hour > h) {
                    break;
                }
            }
            if (hour > h) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    int num = 0;
    vector<int>vec;
    while (cin >> num) {
        vec.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int h = 0;
    cin >> h;
    int ans = Solution().minEatingSpeed(vec, h);
    cout << ans << endl;
    while (1);
}