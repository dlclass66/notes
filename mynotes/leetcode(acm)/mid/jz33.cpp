//先假设可以 那么post排序就可以得到中序遍历 然后看这样的中序和后序是否可以构造出二叉树



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> in = postorder;
        sort(in.begin(), in.end());
        return help(postorder, in, 0, in.size() - 1, 0, in.size() - 1);
    }
    bool help(vector<int>& postorder, vector<int>& in, int postb, int poste, int inb, int ine) {
        if (postb > poste) {
            return true;
        }
        int i = inb;
        for (; i <= ine; i++) {
            if (in[i] == postorder[poste]) {
                break;
            }
        }
        if (i > ine) {
            return false;
        }
        return help(postorder, in, postb, postb + i - 1 - inb, inb, i - 1) && help(postorder, in, postb + i - inb, poste - 1, i + 1, ine);
    }
};


int main() {
    int num = 0;
    vector<int> post;
    while (cin >> num) {
        post.push_back(num);
    }
    bool ans = Solution().verifyPostorder(post);
    cout << ans;
    while (1);
}