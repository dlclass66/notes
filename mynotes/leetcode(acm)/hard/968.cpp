//输入格式 数组 数字间用空格隔开 
//每一个节点有三种情况 第一种已经被摄像头覆盖 第二种未覆盖 第三种有摄像头 叶子节点不需要摄像头 所以所有空节点就是已覆盖
//注意先判断子节点有没有未覆盖的 再判断有没有摄像头




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
    int result = 0;
    int minCameraCover(TreeNode* root) {
        result = 0;
        if (help(root) == 0) {
            result++;
        }
        return result;
    }
    int help(TreeNode* root) {
        if (root == nullptr) {
            return 1;
        }
        int left = help(root->left);
        int right = help(root->right);
        if (left == 0 || right == 0) {
            result++;
            return 2;
        }
        else if (left == 2 || right == 2) {
            return 1;
        }
        else if (left == 1 && right == 1) {
            return 0;
        }
        return -1;
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
    int ans = Solution().minCameraCover(node);
    cout << ans;
    while (1);
}