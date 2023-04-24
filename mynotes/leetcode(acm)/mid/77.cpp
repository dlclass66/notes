//输入格式 输入n k 中间用空格隔开
//回溯算法 注意回溯的取消操作 可以进行简单的剪枝优化效率 用n叉树理解回溯



#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vec.reserve(k);
        backtrack(n, k, 1);
        return ans;
    }
    void backtrack(int n, int k, int start) {
        if (vec.size() == k) {
            ans.push_back(vec);
        }
        for (int i = start; i <= n; i++) {
            vec.push_back(i);
            if (n - i >= k - vec.size()) {
                backtrack(n, k, i + 1);
            }
            vec.pop_back();
        }
    }
};
int main() {
    int n = 0;
    cin >> n;
    int k = 0;
    cin >> k;
    vector<vector<int>> ans = Solution().combine(n, k);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    while (1);
}