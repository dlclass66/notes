//递归 使用数组收集结果即可


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        :val(0), left(nullptr), right(nullptr){}
    TreeNode(int x)
        :val(x), left(nullptr), right(nullptr){}
};
 
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> vec;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return ans;
        }
        dfs(root, targetSum);
        return ans;
    }
    void dfs(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                ans.push_back(vec);
                ans.back().push_back(root->val);
            }
            return;
        }
        if (root->left != nullptr) {
            vec.push_back(root->val);
            dfs(root->left, targetSum - root->val);
            vec.pop_back();
        }
        if (root->right != nullptr) {
            vec.push_back(root->val);
            dfs(root->right, targetSum - root->val);
            vec.pop_back();
        }
    }
};
TreeNode* create(vector<int>& nums) {
    if (nums.size() == 0 || nums[0] == -1) {
        return nullptr;
    }
    int size = nums.size();
    vector<TreeNode*> treevec(size);
    for (int i = 0; i < size; i++) {
        if (nums[i] == -1) {
            treevec[i] = nullptr;
            continue;
        }
        treevec[i] = new TreeNode(nums[i]);
    }
    for (int i = 0; i < size; i++) {
        if (treevec[i] == nullptr) {
            continue;
        }
        if (i * 2 + 1 < size) {
            treevec[i]->left = treevec[i * 2 + 1];
        }
        if (i * 2 + 2 < size) {
            treevec[i]->right = treevec[i * 2 + 2];
        }
    }
    return treevec[0];
}
int main() {
    int num = 0;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
        if (getchar() == '\n') {
            break;
        }
    }
    int target = 0;
    cin >> target;
    TreeNode* root(create(nums));
    vector<vector<int>> ans = Solution().pathSum(root, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}