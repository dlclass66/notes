//层序遍历 找出每行最大值即可 INT_MIN 表示int可以表示的最小值



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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            int maxnum = INT_MIN;
            while (size > 0) {
                TreeNode* cur = qu.front();
                qu.pop();
                maxnum = max(maxnum, cur->val);
                if (cur->left != nullptr) {
                    qu.push(cur->left);
                }
                if (cur->right != nullptr) {
                    qu.push(cur->right);
                }
                size--;
            }
            ans.push_back(maxnum);
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
    vector<int> ans = Solution().largestValues(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}