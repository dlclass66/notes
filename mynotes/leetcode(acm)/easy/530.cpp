//使用一个treenode* 存储前一个节点的指针 初始化为nullptr 这样第一个节点就容易判断


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
    int mindif = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        help(root);
        return mindif;
    }
    void help(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        help(root->left);
        if (pre == nullptr) {
            pre = root;
        }
        else {
            mindif = min(root->val - pre->val, mindif);
            pre = root;
        }
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
    int ans = Solution().getMinimumDifference(root);
    cout << ans;
    while (1);
}