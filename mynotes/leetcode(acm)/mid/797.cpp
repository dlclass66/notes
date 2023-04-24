//输入格式 每行一个int数组 数字间用空格隔开
//dfs 回溯 



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vec.reserve(graph.size());
        dfs(graph, 0);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, int cur) {
        if (cur == graph.size() - 1) {
            ans.push_back(vec);
            ans.back().push_back(cur);
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            vec.push_back(cur);
            dfs(graph, graph[cur][i]);
            vec.pop_back();
        }
    }
};
int main() {
    int num = 0;
    vector<vector<int>> graph;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            graph.push_back(nums);
            nums.clear();
        }
    }
    graph.push_back(nums);
    vector<vector<int>> ans = Solution().allPathsSourceTarget(graph);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}