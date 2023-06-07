//回溯算法 注意去重
//用一个vector<bool> vis记录每个元素是否被访问过（下标） 一个unordered_set<int> visited记录当前层已经访问过的元素




#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;



class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<bool> vis;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vis = vector<bool>(nums.size(), false);
        help(nums, 0);
        return ans;
    }

    void help(vector<int>& nums, int cur) {
        if (vec.size() == nums.size()) {
            ans.push_back(vec);
            return;
        }
        unordered_set<int> visited;
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i] || visited.find(nums[i]) != visited.end()) {
                continue;
            }
            vec.push_back(nums[i]);
            vis[i] = true;
            visited.insert(nums[i]);
            help(nums, cur + 1);
            vis[i] = false;
            vec.pop_back();
        }
    }

};

int main() {
    int n = 0;
    vector<int> nums;
    while (cin >> n) {
		nums.push_back(n);
	}
    vector<vector<int>> ans = Solution().permuteUnique(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
    while (1);
}