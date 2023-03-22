//输出格式 每一行是一个数组 数字之间用空格隔开
//一个大循环是要填入的数 里面4个小循环 需要判断是否已被填上数字
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int num = 1;
        int k = 0;
        while (num <= n * n) {
            for (int i = k; i < n - k; i++) {
                if (ans[k][i] != 0) {
                    break;
                }
                ans[k][i] = num;
                num++;
            }
            for (int i = k + 1; i < n - k; i++) {
                if (ans[i][n - k - 1] != 0) {
                    break;
                }
                ans[i][n - k - 1] = num;
                num++;
            }
            for (int i = n - k - 2; i >= k; i--) {
                if (ans[n - k - 1][i] != 0) {
                    break;
                }
                ans[n - k - 1][i] = num;
                num++;
            }
            for (int i = n - k - 2; i >= k + 1; i--) {
                if (ans[i][k] != 0) {
                    break;
                }
                ans[i][k] = num;
                num++;
            }
            k++;
        }
        return ans;
    }
};
int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> ans = Solution().generateMatrix(n);
    for (auto& vec1 : ans) {
        for (int i : vec1) {
            cout << i << ' ';
        }
        cout << endl;
    }
    while (1);
}