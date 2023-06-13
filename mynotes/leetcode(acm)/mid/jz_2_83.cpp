//使用回溯算法 需要一个vis数组记录是否已经使用该数字



#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<bool> vis;
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> permute(vector<int>& nums) {
        vis = vector<bool>(nums.size(), false);
        vec.reserve(nums.size());
        help(nums);
        return ans;
    }

    void help(vector<int>& nums) {
        if (vec.size() == nums.size()) {
            ans.push_back(vec);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i]) {
                continue;
            }
            else {
                vis[i] = true;
                vec.push_back(nums[i]);
                help(nums);
                vis[i] = false;
                vec.pop_back();
            }
        }
    }
};



int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
		nums.push_back(num);
	}
    vector<vector<int>> ans = Solution().permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
    
    while (1);
}