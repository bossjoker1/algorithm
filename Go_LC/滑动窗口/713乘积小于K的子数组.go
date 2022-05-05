package main

// 注意右边界不能处于左边界的左边
func numSubarrayProductLessThanK(nums []int, k int) int {
    n := len(nums)
    l, r := 0, 0
    res := 0
    tmp := 1
    for l < n{
        for r < n && tmp * nums[r] < k {
            tmp *= nums[r]
            r ++
        }
        res += r - l
        tmp /= nums[l] 
        l ++
		// 重新以l开始
        if r < l {
            r = l
            tmp = 1
        }
    }

    return res
}