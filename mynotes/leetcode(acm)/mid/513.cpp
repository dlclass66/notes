//使用层序遍历 


#include <iostream>
#include <vector>
#include <queue>
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
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            int i = size;
            while (i > 0) {
                TreeNode* cur = qu.front();
                qu.pop();
                if (i == size) {
                    ans = cur->val;
                }
                if (cur->left != nullptr) {
                    qu.push(cur->left);
                }
                if (cur->right != nullptr) {
                    qu.push(cur->right);
                }
                i--;
            }
        }
        return ans;
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
    int ans = Solution().findBottomLeftValue(root);
    cout << ans;
    while (1);
}