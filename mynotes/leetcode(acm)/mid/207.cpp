//拓扑排序 类似与bfs 入度为0的节点入队 用unordered_map统计每门课程的后续课程 如果最后每门课程都能入队 则可以完成所以课程的学习


#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count = 0;
        queue<int> qu;
        unordered_map<int, vector<int>> hash;
        vector<int> in(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            hash[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                qu.push(i);
            }
        }
        while (!qu.empty()) {
            int num = qu.front();
            qu.pop();
            count++;
            for (int i = 0; i < hash[num].size(); i++) {
                in[hash[num][i]]--;
                if (in[hash[num][i]] == 0) {
                    qu.push(hash[num][i]);
                }
            }
        }
        return count == numCourses;
    }

};



int main() {
    int numc = 0;
    cin >> numc;
    int num = 0;
    vector<int> nums(2, 0);
    vector<vector<int>> vec;
    int i = 0;
    while (cin >> num) {
        nums[i] = num;
        i++;
        if (i == 2) {
            vec.push_back(nums);
            i = 0;
        }
    }
    bool ans = Solution().canFinish(numc, vec);
    cout << ans;
    while (1);
}