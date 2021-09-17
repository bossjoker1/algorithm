// leetcode .538
//继续学习递归思想
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
    int sum = 0;//记录和
    void traverse(TreeNode* root){
        if(root == NULL) return;
        //反向中序遍历
        traverse(root->right);
        sum+=root->val;
        root->val = sum;
        traverse(root->left);
    }
};