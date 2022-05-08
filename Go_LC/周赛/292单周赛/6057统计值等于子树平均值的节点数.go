package main

// 递归返回节点个数和相加的值
// 可以尝试写闭包函数

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func averageOfSubtree(root *TreeNode) int {
    res := 0
    query(&res, root)

    return res
}

func query(cnt *int, root *TreeNode) (int, int){
    if root == nil{
        return 0, 0
    }
    cs, cc := root.Val, 1
    s, c := query(cnt, root.Left)
    cs += s
    cc += c
    s, c = query(cnt, root.Right)
    cs += s
    cc += c

    if cs / cc == root.Val{
        *cnt ++
    }
    return cs, cc
}