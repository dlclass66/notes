//输入格式 以数组输入二叉树
//最长路径就是该节点左右的高度（到叶子节点的最大节点数）之和


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
    int diameterOfBinaryTree(TreeNode* root) {
        help(root);
        return ans - 1;
    }
    int help(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left = help(root->left);
        int right = help(root->right);
        ans = max(ans, left + right + 1);
        return max(left, right) + 1;
    }
};

TreeNode* creat(const vector<int>& vec) {
    int size = vec.size();
    vector<TreeNode*> treevec(size, nullptr);
    for (int i = 0; i < size; i++) {
        if (vec[i] == -1) {
            continue;
        }
        TreeNode* cur = new TreeNode(vec[i]);
        treevec[i] = cur;
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
    TreeNode* root(creat(nums));
    int ans =  Solution().diameterOfBinaryTree(root);
    cout << ans;
    while (1);
}