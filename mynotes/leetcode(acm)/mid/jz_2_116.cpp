//使用并查集即可



#include <iostream>
#include <vector>

using namespace std;



class Solution {
private:
    vector<int> fa;
private:
    int find(int x) {
        while (x != fa[x]) {
            x = fa[x];
        }
        return x;
    }
    void add(int x, int y) {
        x = find(x);
        y = find(y);
        fa[y] = x;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        fa = vector<int>(isConnected.size(), 0);
        for (int i = 0; i < fa.size(); i++) {
            fa[i] = i;
        }
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[0].size(); j++) {
                if (i != j && isConnected[i][j] == 1) {
                    add(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < fa.size(); i++) {
            if (fa[i] == i) {
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> edges;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
			edges.push_back(nums);
			nums.clear();
		}
    }
    edges.push_back(nums);
    int ans = Solution().findCircleNum(edges);
    cout << ans;
    while (1);
}