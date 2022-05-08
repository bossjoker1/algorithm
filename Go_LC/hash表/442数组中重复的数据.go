// 原地hash, 由数据范围可知 通过加符号标识是否已经出现
// 注意取绝对值
func findDuplicates(nums []int) (ans []int) {
    for _, x := range nums {
        if x < 0 {
            x = -x
        }
        if nums[x-1] > 0 {
            nums[x-1] = - nums[x-1]
        } else {
            ans = append(ans, x)
        }
    }
    return
}
