//输入格式 每一行一个数组 数字用空格隔开
//输出 数字中间用空格隔开
//注意循环1 3 之间的冲突 和循环2 4 之间的冲突
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int count = m * n;
        int k = 0;
        vector<int> ans;
        while (count > 0) {
            for (int i = k; i <= n - k - 1; i++) {
                ans.push_back(matrix[k][i]);
                count--;
            }
            for (int i = k + 1; i <= m - k - 1; i++) {
                ans.push_back(matrix[i][n - k - 1]);
                count--;
            }
            if (count == 0) {
                break;
            }//因为循环3可能与1冲突
            for (int i = n - k - 2; i >= k; i--) {
                ans.push_back(matrix[m - k - 1][i]);
                count--;
            }
            if (count == 0) {
                break;
            }//因为循环4可能跟2冲突
            for (int i = m - k - 2; i > k; i--) {
                ans.push_back(matrix[i][k]);
                count--;
            }
            k++;
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> matrix;
    vector<int> temp;
    int num = 0;
    while (cin >> num) {
        temp.push_back(num);
        if (getchar() == '\n') {
            matrix.push_back(temp);
            temp.clear();
        }
    }
    matrix.push_back(temp);
    vector<int> ans;
    ans = Solution().spiralOrder(matrix);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}