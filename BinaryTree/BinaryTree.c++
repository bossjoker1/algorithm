//114. Flatten Binary Tree to Linked List

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        root->right = left;
        TreeNode* p = root;
        while(p->right) p = p->right;
        p->right = right;
    }
};

//116. Populating Next Right Pointers in Each Node
//递归做法空间复杂度很高，可以考虑设一个pre然后对其孩子进行判断
class Solution {
public:
    Node* connect(Node* root) {
      if(root == NULL) return NULL;
      connectRight(root->left, root->right);
      return root;  
    }

    void connectRight(Node *node1, Node *node2){
        if(node1 == NULL||node2 == NULL) return;
        node1->next = node2;
        connectRight(node1->left, node1->right);
        connectRight(node2->left, node2->right);
        connectRight(node1->right, node2->left);
    }
};

//最强的dfs递归，java代码实现
    public Node connect(Node root) {
        dfs(root, null);
        return root;
    }

    private void dfs(Node curr, Node next) {
        if (curr == null)
            return;
        curr.next = next;
        dfs(curr.left, curr.right);
        dfs(curr.right, curr.next == null ? null : curr.next.left);
    }