package main

type pair struct{
    idx, val int
}

// 田忌赛马
func advantageCount(nums1 []int, nums2 []int) []int {
    n := len(nums1)
    // nums1 升序排序
    sort.Ints(nums1)

    // pairs 记录索引和值，按值大小升序排序
    pairs := make([]pair, n)

    for i, v := range nums2{
        pairs[i].idx = i
        pairs[i].val = v 
    }

    sort.Slice(pairs, func(i, j int) bool{
        return  pairs[i].val < pairs[j].val
    })

    res := make([]int, n)

    l, r := 0, 0
    back := n-1
    for l < n{
        if nums1[l] > pairs[r].val{
            res[pairs[r].idx] = nums1[l]
            r ++
        }else{
            res[pairs[back].idx] = nums1[l]
            back --
        }
        l++
    }

    return res
}