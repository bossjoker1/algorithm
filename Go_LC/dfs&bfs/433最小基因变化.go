package main

// 居然直接ac了，没想到啊，才刚上手go嘿嘿嘿

func minMutation(start string, end string, bank []string) int {
    n := len(bank)
    res := 15
    visited := make([]int, n)
    dfs(start, end, visited, bank, &res, 0)
    if res == 15{
        return -1
    }
    return res
}


func dfs(start string, end string, vis []int, bank []string, res *int, step int){
    for i:=0; i<len(bank); i++{
        if start == end{
            *res = min(*res, step)
            return 
        }
        if vis[i] != 0{
            continue
        }
        cnt := 0
        for j:=0; j<8; j++{
            if start[j] != bank[i][j]{
                cnt++
            }
        }
        if cnt == 1{
            vis[i] = 1
            dfs(bank[i], end, vis, bank, res, step+1)
            vis[i] = 0
        }
    }
}

func min(x, y int) int{
    if x < y{
        return x
    }else{
        return y
    }
}


// bfs
func minMutation2(start, end string, bank []string) int {
    if start == end {
        return 0
    }
    bankSet := map[string]struct{}{}
    for _, s := range bank {
        bankSet[s] = struct{}{}
    }
    if _, ok := bankSet[end]; !ok {
        return -1
    }

    q := []string{start}
    for step := 0; q != nil; step++ {
        tmp := q
        q = nil
        for _, cur := range tmp {
            for i, x := range cur {
                for _, y := range "ACGT" {
                    if y != x {
                        nxt := cur[:i] + string(y) + cur[i+1:]
                        if _, ok := bankSet[nxt]; ok {
                            if nxt == end {
                                return step + 1
                            }
                            delete(bankSet, nxt)
                            q = append(q, nxt)
                        }
                    }
                }
            }
        }
    }
    return -1
}

