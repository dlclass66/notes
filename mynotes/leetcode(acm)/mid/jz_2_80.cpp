//使用回溯算法即可 可以稍微剪枝


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> combine(int n, int k) {
        vec.reserve(k);
        help(n, k, 1);
        return ans;
    }

    void help(int n, int k, int start) {
        if (n - start + 1 + vec.size() < k) {
            return;
        }
        if (vec.size() == k) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i <= n; i++) {
            vec.push_back(i);
            help(n, k, i + 1);
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
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    while (1);
}#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> combine(int n, int k) {
        vec.reserve(k);
        help(n, k, 1);
        return ans;
    }

    void help(int n, int k, int start) {
        if (n - start + 1 + vec.size() < k) {
            return;
        }
        if (vec.size() == k) {
            ans.push_back(vec);
            return;
        }
        for (int i = start; i <= n; i++) {
            vec.push_back(i);
            help(n, k, i + 1);
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
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    while (1);
}