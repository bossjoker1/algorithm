//前序中序数组，构建二叉树，用unordered_map构建映射，快速查找到根节点的位置。
class Solution {
    unordered_map<int, int> mp;
    int idx = 0, n;
public:
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        n = in.size();
        for (int i = 0; i < n; ++i) mp[in[i]] = i;
        return bt(pre, 0, n - 1);
    }

    TreeNode* bt(vector<int>& pre, int l, int r) {
        if (l > r) return nullptr;
        int i = mp[pre[idx]];

        TreeNode* root = new TreeNode(pre[idx++]);
        root->left = bt(pre, l, i - 1);
        root->right = bt(pre, i + 1, r);
        return root;
    }
};

//中序后序很简单，套模板就行，包括前序后序（根据输入建立其中一种），懒得刷了
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1, 0, postorder.size()-1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
        //base case
        if(inStart > inEnd || postStart > postEnd) return NULL;
        TreeNode * root = new TreeNode(postorder[postEnd]);

        int index = inStart;
        while(inorder[index]!= postorder[postEnd]) index++;

        root->left = helper(inorder, postorder, inStart, index - 1, postStart, postStart+index - inStart -1);
        root->right = helper(inorder, postorder, index+1,inEnd, postStart + index - inStart, postEnd-1);
        return root;
    } 
};
