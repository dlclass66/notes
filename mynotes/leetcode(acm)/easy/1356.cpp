//输入格式数组 数字间用空格隔开
//关键是求1数量的方法 一种是从最后一位一个一个求 另一种效率更高的是 n与n-1 求与 消掉最后一个1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 

class Solution {
public:
    static int bitcount(int x) {
        int ans = 0;
        while (x > 0) {
            x &= x - 1;
            ans++;
        }
        return ans;
    }
    struct cmp {
        bool operator()(int x, int y) {
            int bitx = bitcount(x);
            int bity = bitcount(y);
            if (bitx == bity) {
                return x < y;
            }
            else {
                return bitx < bity;
            }
        }
    };
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp());
        return arr;
    }
};


int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    vector<int> ans = Solution().sortByBits(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}