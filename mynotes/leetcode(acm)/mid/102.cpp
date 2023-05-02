//使用队列 每一层使用一个size记录大小


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<vector<int>> ans;
        vector<int> vec;
        if (root == nullptr) {
            return ans;
        }
        qu.push(root);
        while (!qu.empty()) {
            int i = qu.size();
            vec.clear();
            while (i > 0) {
                TreeNode* temp = qu.front();
                qu.pop();
                vec.push_back(temp->val);
                if (temp->left != nullptr) {
                    qu.push(temp->left);
                }
                if (temp->right != nullptr) {
                    qu.push(temp->right);
                }
                i--;
            }
            ans.push_back(vec);
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
        if (2 * i + 1 < size) {
            treevec[i]->left = treevec[2 * i + 1];
        }
        if (2 * i + 2 < size) {
            treevec[i]->right = treevec[2 * i + 2];
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
    vector<vector<int>> ans = Solution().levelOrder(root);
    for (int i = 0; i < ans.size(); i++) {
        for (int j : ans[i]) {
            cout << j << ' ';
        }
        cout << endl;
    }
    while (1);
}