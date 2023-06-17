//开始时准备每个1都进行dfs 会超时
//后来考虑采用动态规划算法 但是因为有4个方向 所以得遍历两次 
//注意左上角和右下角的初始化 



#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat[0][0] == 1) {
            mat[0][0] = 100000;
        }
        if (mat.back().back() == 1) {
            mat.back().back() = 100000;
        }
        for (int j = 1; j < mat[0].size(); j++) {
            if (mat[0][j] != 0) {
                mat[0][j] = mat[0][j - 1] + 1;
            }
        }
        for (int i = 1; i < mat.size(); i++) {
            if (mat[i][0] != 0) {
                mat[i][0] = mat[i - 1][0] + 1;
            }
            for (int j = 1; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    continue;
                }
                mat[i][j] = min(mat[i - 1][j], mat[i][j - 1]) + 1;
            }
        }
        for (int j = mat[0].size() - 2; j >= 0; j--) {
            mat[mat.size() - 1][j] = min(mat[mat.size() - 1][j],
                mat[mat.size() - 1][j + 1] + 1);
        }
        for (int i = mat.size() - 2; i >= 0; i--) {
            mat[i][mat[0].size() - 1] = min(mat[i][mat[0].size() - 1],
                mat[i + 1][mat[0].size() - 1] + 1);
            for (int j = mat[0].size() - 2; j >= 0; j--) {
                mat[i][j] = min(mat[i][j], min(mat[i + 1][j], mat[i][j + 1]) + 1);
            }
        }
        return mat;
    }
};

int main() {
    int num = 0;
    vector<vector<int>> mat;
    vector<int>vec;
    while (cin >> num) {
        vec.push_back(num);
        if (getchar() == '\n') {
			mat.push_back(vec);
			vec.clear();
		}
    }
    mat.push_back(vec);
    vector<vector<int>> ans = Solution().updateMatrix(mat);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}