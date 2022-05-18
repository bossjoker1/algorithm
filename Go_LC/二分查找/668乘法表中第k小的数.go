package main

// 二分查找
// 对一个数，每一行比它小的个数比较好确定
func findKthNumber(m int, n int, k int) int {
    if m > n {
        m, n = n, m
    }
    left, right := 0, m * n
    check := func(x int) (sum int) {
        for i := 1; i <= m; i++ {
            if cur := x / i; cur <= n {
                sum += cur
            } else {
                sum += n
            }
        }
        return
    }
    for left < right {
        mid := (left + right) >> 1
        if check(mid) >= k {
            right = mid
        } else {
            left = mid + 1
        }
    }
    return left
}
