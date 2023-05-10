//从外向内反转 注意顶点上的点会被覆盖


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        int n = matrix.size();
        while (start < n / 2) {
            for (int i = start + 1; i < n - start - 1; i++) {
                swap(matrix[start][i], matrix[i][n - 1 - start]);
                swap(matrix[n - 1 - start][n - 1 - i], matrix[start][i]);
                swap(matrix[n - 1 - i][start], matrix[start][i]);
            }
            swap(matrix[start][start], matrix[start][n - 1 - start]);
            swap(matrix[start][start], matrix[n - 1 - start][n - 1 - start]);
            swap(matrix[start][start], matrix[n - 1 - start][start]);
            start++;
        }
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> matrix;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            matrix.push_back(nums);
            nums.clear();
        }
    }
    if (!nums.empty()) {
        matrix.push_back(nums);
    }
    Solution().rotate(matrix);
    for (vector<int>& vec : matrix) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    while (1);
}