package main

func minDeletionSize(strs []string) int {
    res := 0
    n := len(strs[0])

    for i:=0;i<n; i++{
        pre := byte('a')
        for _, sub :=  range strs{
            if sub[i] < pre{
                res ++
                break
            }
            pre = sub[i]
        }
    }

    return res
}