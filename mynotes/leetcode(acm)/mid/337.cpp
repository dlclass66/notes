//输入格式 数组 数字间用空格隔开
//二叉树的构造 使用数组 类似于层序遍历完全二叉树 空节点用-1表示 
//要把子节点的信息传上来 使用后序遍历 每个子节点可以偷或者不偷 使用一个数组分别存储两种情况的最大值
//注意不偷父节点 应该在子节点偷或者不偷中取大的 而不是偷子节点




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
    int rob(TreeNode* root) {
        vector<int> ans(robtree(root));
        return max(ans[0], ans[1]);
    }
    vector<int> robtree(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>({ 0, 0 });
        }
        vector<int> left(robtree(root->left));
        vector<int> right(robtree(root->right));

        vector<int> dp(2, 0);
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        dp[1] = left[0] + right[0] + root->val;
        return dp;
    }
};
    TreeNode* creattree(vector<int>& vec) {
        if (vec[0] == -1) {
            return nullptr;
        }
        vector<TreeNode*> treevec(vec.size(), nullptr);
    
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == -1) {
                treevec[i] = nullptr;
            }
            else {
                TreeNode* node = new TreeNode(vec[i]);
                treevec[i] = node;
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i] == -1) {
                continue;
            }
            if (2 * i + 1 < vec.size()) {
                treevec[i]->left = treevec[2 * i + 1];
            }
            if (2 * i + 2 < vec.size()) {
                treevec[i]->right = treevec[2 * i + 2];
            }
        }
        return treevec[0];
    }
int main() {
    int num = 0;
    vector<int> vec;
    while (cin >> num) {
        vec.push_back(num);
    }
    TreeNode* node = creattree(vec);
    int ans = Solution().rob(node);
    cout << ans;
    while (1);
}