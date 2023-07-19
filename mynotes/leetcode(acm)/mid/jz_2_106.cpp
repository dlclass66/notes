//使用并查集 判断是否是二分图
//遍历graph 每个节点的所有邻接点 如果邻接点和当前节点已经在一个集合中 则返回false 否则将邻接点和邻接点数组的第一个元素合并


#include <vector>
#include <iostream>


using namespace std;

class Solution {
private:
    vector<int> fa;
private:
    int find(int a) {
        while (fa[a] != a) {
            a = fa[a];
        }
        return a;
    }
    bool same(int a, int b) {
        a = find(a);
        b = find(b);
        return a == b;
    }
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        fa[a] = b;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        fa = vector<int>(graph.size());
        for (int i = 0; i < fa.size(); i++) {
            fa[i] = i;
        }
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (same(i, graph[i][j])) {
                    return false;
                }
                else {
                    join(graph[i][0], graph[i][j]);
                }
            }
        }
        return true;
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> graph;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            graph.push_back(nums);
            nums.clear();
        }
    }
    if (!nums.empty()) {
        graph.push_back(nums);
    }
    bool ans = Solution().isBipartite(graph);
    cout << ans;
    while (1);
}
