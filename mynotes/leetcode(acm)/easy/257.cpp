//可以采用类似深搜的方法 可以先用一个int数组保存 最后再转换成string（见第二种方式）


#include <iostream>
#include <vector>
#include <string>
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
    vector<string> ans;
    string str;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return ans;
        }
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(str);
            ans.back() += to_string(root->val);
            return;
        }
        if (root->left != nullptr) {
            str += to_string(root->val);
            str.push_back('-');
            str.push_back('>');
            dfs(root->left);
            int i = str.size() - 2;
            str.pop_back();
            while (i >= 0 && str[i] != '>') {
                str.pop_back();
                i--;
            }
        }
        if (root->right != nullptr) {
            str += to_string(root->val);
            str.push_back('-');
            str.push_back('>');
            dfs(root->right);
            int i = str.size() - 2;
            str.pop_back();
            while (i >= 0 && str[i] != '>') {
                str.pop_back();
                i--;
            }
        }
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
    vector<string> ans = Solution().binaryTreePaths(root);
    for (string& str : ans) {
        cout << str << endl;
    }
    while (1);
}



//第二种 使用int数组暂存

#include <iostream>
#include <vector>
#include <string>
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
    vector<string> ans;
    vector<int> vec;
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return ans;
        }
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            string str;
            for (int i = 0; i < vec.size(); i++) {
                str += to_string(vec[i]);
                str += "->";
            }
            str += to_string(root->val);
            ans.push_back(str);
            return;
        }
        if (root->left != nullptr) {
            vec.push_back(root->val);
            dfs(root->left);
            vec.pop_back();
        }
        if (root->right != nullptr) {
            vec.push_back(root->val);
            dfs(root->right);
            vec.pop_back();
        }
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
    vector<string> ans = Solution().binaryTreePaths(root);
    for (string& str : ans) {
        cout << str << endl;
    }
    while (1);
}