//递归法 完全二叉树的子树迟早会成为完美二叉树 （子树一直向左 一直向右深度相同）可以更快得到结果
//更简单的方法是层序遍历 但是效率较低


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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftdepth = 0;
        int rightdepth = 0;
        TreeNode* rleft = root->left;
        TreeNode* rright = root->right;
        while (rleft != nullptr) {
            rleft = rleft->left;
            leftdepth++;
        }
        while (rright != nullptr) {
            rright = rright->right;
            rightdepth++;
        }
        if (leftdepth == rightdepth) {
            return pow(2, leftdepth + 1) - 1;
        }
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
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
    int ans = Solution().countNodes(root);
    cout << ans;
    while (1);
}