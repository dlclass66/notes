//使用递归 中序遍历 相等的一定是挨着的  



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
    vector<int> ans;
    int maxcount;
    int count;
    TreeNode* pre;
    vector<int> findMode(TreeNode* root) {
        help(root);
        return ans;
    }
    void help(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        help(root->left);
        if (pre == nullptr) {
            maxcount = 1;
            count = 1;
            ans.push_back(root->val);
            pre = root;
        }
        else {
            if (root->val == pre->val) {
                count++;
            }
            else {
                count = 1;
            }
            if (count >= maxcount) {
                if (count > maxcount) {
                    ans.clear();
                    ans.push_back(root->val);
                }
                else {
                    if (*(ans.end() - 1) != root->val) {
                        ans.push_back(root->val);
                    }
                }
                maxcount = count;
            }
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
    vector<int> ans = Solution().findMode(root);
    for (int i : ans) {
        cout << i << ' ';
    }
    while (1);
}