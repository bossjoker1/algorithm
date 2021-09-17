// 就是先判断子序列，简单的贪心算法，双指针
// 根据字典序选出符合要求的最小的字符串
func findLongestWord(s string, dictionary []string) (ans string) {
    for _, t := range dictionary {
        i := 0
        for j := range s {
            if s[j] == t[i] {
                i++
                if i == len(t) {
                    if len(t) > len(ans) || len(t) == len(ans) && t < ans {
                        ans = t
                    }
                    break
                }
            }
        }
    }
    return
}