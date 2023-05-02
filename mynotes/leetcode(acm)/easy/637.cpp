//层序遍历求平均值即可


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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            double sum = 0;
            int i = size;
            while (i > 0) {
                TreeNode* cur = qu.front();
                qu.pop();
                sum += cur->val;
                if (cur->left != nullptr) {
                    qu.push(cur->left);
                }
                if (cur->right != nullptr) {
                    qu.push(cur->right);
                }
                i--;
            }
            ans.push_back(sum / size);
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
    vector<double> ans = Solution().averageOfLevels(root);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    while (1);
}