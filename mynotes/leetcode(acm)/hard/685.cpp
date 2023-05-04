//输入格式 二维数组 每行一个数组 数字间用空格隔开
//首先判断有没有入度为2的节点（有两个父节点） 有的话删去其中一条边 看是否能构成树（先删靠后的）
//没有这样的节点说明构成了环 删除成环的边
//判断是不是树或者成环的边使用无向图的方法（并查集）

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 

class Solution {
public:
    vector<int> father;
    void init() {
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        father = vector<int>(1001);
        init();
        vector<int> in(1001, 0);
        int in2 = -1;
        for (int i = 0; i < edges.size(); i++) {
            in[edges[i][1]]++;
            if (in[edges[i][1]] == 2) {
                in2 = edges[i][1];
                break;
            }
        }
        if (in2 != -1) {
            for (int i = edges.size() - 1; i >= 0; i--) {
                if (edges[i][1] == in2) {
                    if (istree(edges, i)) {
                        return edges[i];
                    }
                }
            }
        }
        else {
            return removec(edges);
        }
        return {};
    }
    int find(int x) {
        if (father[x] == x) {
            return x;
        }
        else {
            return find(father[x]);
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void join(int x, int y) {
        father[find(y)] = find(x);
    }
    bool istree(vector<vector<int>>& edges, int de) {
        init();
        for (int i = 0; i < edges.size(); i++) {
            if (i == de) {
                continue;
            }
            if (same(edges[i][0], edges[i][1])) {
                cout << 1;
                return false;
            }
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }
    vector<int> removec(vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            if (same(edges[i][0], edges[i][1])) {
                return edges[i];
            }
            else {
                join(edges[i][0], edges[i][1]);
            }
        }
        return {};
    }
};


int main() {
    int num = 0;
    vector<int> edge(2, 0);
    int i = 0;
    vector<vector<int>> edges;
    while (cin >> num) {
        edge[i] = num;
        i++;
        if (i == 2) {
            edges.push_back(edge);
            i = 0;
        }
    }
    vector<int> ans =  Solution().findRedundantDirectedConnection(edges);
    cout << ans[0] << ' ' << ans[1];
    while (1);
}