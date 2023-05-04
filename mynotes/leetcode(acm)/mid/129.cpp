//输入格式 以数组方式输入二叉树
//类似于深搜带回溯


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
    int ans = 0;
    int path = 0;
    int sumNumbers(TreeNode* root) {
        help(root);
        return ans;
    }
    void help(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            ans += path * 10 + root->val;
        }
        if (root->left != nullptr) {
            int temp = path;
            path = path * 10 + root->val;
            help(root->left);
            path = temp;
        }
        if (root->right != nullptr) {
            int temp = path;
            path = path * 10 + root->val;
            help(root->right);
            path = temp;
        }
    }
};

TreeNode* creattreenode(const vector<int>& nums) {
    vector<TreeNode*> vec(nums.size(), nullptr);
    for (int i = 0; i < vec.size(); i++) {
        if (nums[i] != -1) {
            TreeNode* node = new TreeNode(nums[i]);
            vec[i] = node;
        }
    }
    for (int i = 0; i < nums.size(); i++) {
        if (vec[i] == nullptr) {
            continue;
        }
        if (2 * i + 1 < nums.size()) {
            vec[i]->left = vec[2 * i + 1];
        }
        if (2 * i + 2 < nums.size()) {
            vec[i]->right = vec[2 * i + 2];
        }
    }
    return vec[0];
}
int main() {
    vector<int> nums;
    int num = 0;
    while (cin >> num) {
        nums.push_back(num);
    }
    TreeNode* root = creattreenode(nums);
    int ans = Solution().sumNumbers(root);
    cout << ans;
    while (1);
}