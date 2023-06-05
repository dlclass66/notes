//输入格式 二维数组 空数组用-1表示 每行一个数组 数字间用空格隔开
//使用dfs 每次遍历到终点就将路径加入ans中
//没有环 所以不需要used



#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vec.push_back(0);
        dfs(0, graph.size() - 1, graph);
        return ans;
    }
    void dfs(int cur, int target, vector<vector<int>>& graph) {
        if (cur == target) {
            ans.push_back(vec);
            return;
        }
        for (int i = 0; i < graph[cur].size(); i++) {
            vec.push_back(graph[cur][i]);
            dfs(graph[cur][i], target, graph);
            vec.pop_back();
        }
    }
};

int main() {
    int num = 0;
    vector<int> nums;
    vector<vector<int>> graph;
    while (cin >> num) {
        if (num == -1) {
            graph.push_back(nums);
            continue;
        }
        nums.push_back(num);
        if (getchar() == '\n') {
			graph.push_back(nums);
            nums.clear();
		}
    }
    vector<vector<int>> ans = Solution().allPathsSourceTarget(graph);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    while (1);
}