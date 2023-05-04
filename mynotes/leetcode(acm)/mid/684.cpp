//输入格式 二维数组 每行一个一维数组 数字间用空格隔开
//使用并查集 有一个father数组 保存每个节点的father节点 初始时每个节点的father节点都是自己
//一条边如果还没有加入 边的两端节点的root节点就已经相同了 则是冗余的边 如果不相同 则加入这条边 
//注意加入边时不是修改当前节点的father 而是将边两端root节点的一个链接到另一个 




#include <iostream>
#include <vector>

using namespace std;

 

class Solution {
public:
    vector<int> father;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        father = vector<int>(1001, 0);
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
        vector<int> ans(2, 0);
        for (int i = 0; i < edges.size(); i++) {
            if (same(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return ans;
    }
    int find(int n) {
        if (father[n] == n) {
            return n;
        }
        else {
            return find(father[n]);
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        father[fy] = fx;
        father[x] = fx;
        father[y] = fx;
    }
};


int main() {
    int num = 0;
    vector<int> nums(2, 0);
    vector<vector<int>> vec;
    int i = 0;
    while (cin >> num) {
        nums[i] = num;
        if (i == 1) {
            vec.push_back(nums);
            i = 0;
            continue;
        }
        i++;
    }
    vector<int> ans = Solution().findRedundantConnection(vec);
    cout << ans[0] << ' ' << ans[1];
    while (1);
}