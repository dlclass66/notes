class Solution {
public:
    int maxDepth(Node* root) {
        int ans = 0;
        if(root == nullptr){
            return ans;
        }
        queue<Node*> qu;
        qu.push(root);
        while(!qu.empty()){
            int size = qu.size();
            ans++;
            while(size > 0){
                Node* cur = qu.front();
                qu.pop();
                for(int i = 0; i < cur->children.size(); i++){
                    qu.push(cur->children[i]);
                }
                size--;
            }
        }
        return ans;
    }
};