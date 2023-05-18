//直观的想法是每行进行二分搜索 但是复杂度较高
//复杂度更优的方法是类比二叉搜索树 大于往一个方向走 小于往另外一个方向走


#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }
        if (target < matrix[0][0] || target > matrix[m - 1][n - 1]) {
            return false;
        }
        for (int i = 0; i < m; i++) {
            if (search(matrix, i, target)) {
                return true;
            }
        }
        return false;
    }
    bool search(vector<vector<int>>& matrix, int m, int target) {
        int left = 0;
        int right = matrix[m].size() - 1;
        while (left <= right) {
            if (matrix[m][left] > target || matrix[m][right] < target) {
                return false;
            }
            int mid = (left + right) / 2;
            if (matrix[m][mid] == target) {
                return true;
            }
            else if (matrix[m][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};


int main() {
    int target = 0;
    cin >> target;
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
    matrix.push_back(nums);
    bool ans = Solution().findNumberIn2DArray(matrix, target);
    cout << ans;
    while (1);
}



//复杂度更好的方案
//从左下角出发 大于target就向上 小于就向右

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int x = m - 1;
        int y = 0;
        while (x >= 0 && y < n) {
            if (matrix[x][y] == target) {
                return true;
            }
            else if (matrix[x][y] > target) {
                x -= 1;
            }
            else {
                y += 1;
            }
        }
        return false;
    }
};


int main() {
    int target = 0;
    cin >> target;
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
    matrix.push_back(nums);
    bool ans = Solution().findNumberIn2DArray(matrix, target);
    cout << ans;
    while (1);
}