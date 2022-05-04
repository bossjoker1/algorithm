package main

// 双指针

func isSubsequence(s string, t string) bool {
    l := 0
    n1, n2 := len(s), len(t)
    if n1 == 0{
        return true
    }
    if n1 > n2 {
        return false
    }else{
        for i:=0;i < n2;i++{
            if l == n1{
                return true
            }
            if t[i] == s[l]{
                l ++
            }
        }
    }
    return l == n1
}