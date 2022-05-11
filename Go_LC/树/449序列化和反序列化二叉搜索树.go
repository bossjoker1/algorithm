package main

// 对于二叉树，需给定 (先序遍历 ||  后序遍历) + 中序遍历， 才能恢复
// 对于二叉搜索树，给定先序遍历或后序遍历即可，因为中序遍历可由前者排序得到

// 后序遍历，根节点在数组尾部

import (
	"strings"
	"math"
	"strconv"
)

type Codec struct{}

func Constructor() (_ Codec) { return }

func (Codec) serialize(root *TreeNode) string {
    arr := []string{}
    var postOrder func(*TreeNode)
    postOrder = func(node *TreeNode) {
        if node == nil {
            return
        }
        postOrder(node.Left)
        postOrder(node.Right)
        arr = append(arr, strconv.Itoa(node.Val))
    }
    postOrder(root)
    return strings.Join(arr, " ")
}

func (Codec) deserialize(data string) *TreeNode {
    if data == "" {
        return nil
    }
    arr := strings.Split(data, " ")
    var construct func(int, int) *TreeNode
    construct = func(lower, upper int) *TreeNode {
        if len(arr) == 0 {
            return nil
        }
        val, _ := strconv.Atoi(arr[len(arr)-1])
        if val < lower || val > upper {
            return nil
        }
        arr = arr[:len(arr)-1]
        return &TreeNode{Val: val, Right: construct(val, upper), Left: construct(lower, val)}
    }
    return construct(math.MinInt32, math.MaxInt32)
}
