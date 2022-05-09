package main

// 贪心：每次选最小的和最大的不影响剩下来的数组排序
func diStringMatch(s string) (ans []int) {
    n := len(s)
    l, r := 0, n

    for i := 0; i < n; i++{
        if s[i] == 'I'{
            ans = append(ans, l)
            l ++
        }else{
            ans = append(ans, r)
            r -- 
        }
    }

    ans = append(ans, r)

    return 
}