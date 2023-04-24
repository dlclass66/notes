//输入格式 数组 数字间用空格隔开
//两次遍历 第一次让每一个比其左边评分高的孩子分到更多糖果 第二次让其比右边评分高的分到更多糖果
//注意每个孩子至少有一个糖果 第二次遍历糖果数取较大的


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candys(ratings.size(), 0);
        candys[0] = 1;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candys[i] = candys[i - 1] + 1;
            }
            else {
                candys[i] = 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candys[i] = max(candys[i], candys[i + 1] + 1);
            }
        }
        int ans = 0;
        for (int i : candys) {
            ans += i;
        }
        return ans;
    }
};
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int ans = Solution().candy(nums);
    cout << ans << endl;
    while (1);
}