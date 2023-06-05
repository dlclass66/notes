//使用并查集 第一个还未添加边就已经有同样的父节点的就是要移除的 注意遍历顺序 因为要返回最后出现的 所以从前往后




#include <iostream>
#include <vector>
using namespace std;



class Solution {
private:
    vector<int> fa;
private:
    void add(int x, int y) {
        x = find(x);
        y = find(y);
        fa[y] = x;
    }
    int find(int x) {
        while (fa[x] != x) {
            x = fa[x];
        }
        return x;
    }
    bool same(int x, int y) {
        if (find(x) == find(y)) {
            return true;
        }
        else {
            return false;
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        fa = vector<int>(edges.size() + 1, 0);
        for (int i = 0; i < fa.size(); i++) {
            fa[i] = i;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (same(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            else {
                add(edges[i][0], edges[i][1]);
            }
        }
        return { -1, -1 };
    }
};

int main() {
    int num = 0;
    vector<int> nums(2, 0);
    vector<vector<int>> edges;
    int i = 0;
    while (cin >> num) {
        nums[i] = num;
        i++;
        if (i == 2) {
			edges.push_back(nums);
			i = 0;
		}
    }
    vector<int> ans = Solution().findRedundantConnection(edges);
    cout << ans[0] << ' ' << ans[1];
    while (1);
}