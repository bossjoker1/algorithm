/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> res;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int flag = 0;
        while(!dq.empty()){
            vector<int> tmp;
            int n = dq.size();
            for(int i = 0; i < n; i++){
                TreeNode* node = flag ? dq.back() : dq.front();
                tmp.push_back(node->val);
                if(!flag){
                    if(node->left) dq.push_back(node->left);
                    if(node->right) dq.push_back(node->right);
                    dq.pop_front();
                }else{
                    if(node->right) dq.push_front(node->right);
                    if(node->left) dq.push_front(node->left);
                    dq.pop_back();
                }
            }
            res.push_back(tmp);
            flag = !flag;
        }
        return res;
    }
};


