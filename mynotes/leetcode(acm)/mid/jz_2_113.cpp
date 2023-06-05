//拓扑排序 使用一个数组保存入度 一个unordered_map保存每门课的后续课程
//把入度为0的加入队列 然后遍历队列中的元素 把他们的后续课程的入度减一 如果减到0了就加入队列


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        unordered_map<int, vector<int>> next;
        for (int i = 0; i < prerequisites.size(); i++) {
            in[prerequisites[i][0]]++;
            next[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> qu;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                qu.push(i);
            }
        }
        vector<int> ans;
        int count = 0;
        while (!qu.empty()) {
            int cur = qu.front();
            count++;
            qu.pop();
            ans.push_back(cur);
            for (int j : next[cur]) {
                in[j]--;
                if (in[j] == 0) {
                    qu.push(j);
                }
            }
        }
        if (count < numCourses) {
            return {};
        }
        else {
            return ans;
        }
    }
};

int main() {
    int target = 0;
    cin >> target;
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
    vector<int> ans = Solution().findOrder(target, edges);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    while (1);
}