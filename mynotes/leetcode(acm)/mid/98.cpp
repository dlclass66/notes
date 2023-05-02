//利用二叉搜索树中序遍历有序 递归把中序结果放入数组 遍历数组看是否有序


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
    vector<int> inorder;
    bool isValidBST(TreeNode* root) {
        help(root);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i - 1]) {
                return false;
            }
        }
        return true;
    }
    void help(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        help(root->left);
        inorder.push_back(root->val);
        help(root->right);
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
    }
    TreeNode* root(create(nums));
    bool ans = Solution().isValidBST(root);
    cout << ans;
    while (1);
}