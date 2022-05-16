package main

// 返回给定节点的中序后继
// 二叉搜索树的性质
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func inorderSuccessor(root *TreeNode, p *TreeNode) *TreeNode {
    // 二叉搜索树
    if root == nil{
        return nil
    }

    if p.Val >= root.Val{
        return inorderSuccessor(root.Right, p)
    }

    node := inorderSuccessor(root.Left, p)

    if node == nil{
        return root
    }else{
        return node
    }
    
}
