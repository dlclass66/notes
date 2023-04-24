//回溯算法 sum可以作为参数 也可以放在外面作为全局变量 可以简单剪枝



include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    int sum = 0;
    vector<vector<int>> combinationSum3(int k, int n) {
        vec.reserve(k);
        backtrack(k, n, 1);
        return ans;
    }
    void backtrack(int k, int n, int start) {
        if (vec.size() == k) {
            if (sum == n) {
                ans.push_back(vec);
            }
        }
        for (int i = start; i <= 9; i++) {
            vec.push_back(i);
            sum += i;
            if (sum <= n && 9 - i >= k - vec.size()) {
                backtrack(k, n, i + 1);
            }
            vec.pop_back();
            sum -= i;
        }
    }
};
int main() {
    int n = 0;
    cin >> n;
    int k = 0;
    cin >> k;
    vector<vector<int>> ans = Solution().combinationSum3(n, k);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < k; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    while (1);
}