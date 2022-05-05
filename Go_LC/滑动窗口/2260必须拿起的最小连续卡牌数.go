package main

func minimumCardPickup(cards []int) int {
    mp := map[int]int{}
    l, r := 0, 0
    n := len(cards)
    res := 100005
    for r < n{
        if mp[cards[r]] == 0{
			// 为了区分索引0，所以给所有索引+1
            mp[cards[r]] = r + 1 
            r ++
        }else{
            for mp[cards[r]] != 0{
                res = min(res, r - mp[cards[r]] + 2)
                mp[cards[l]] = 0 
                l ++
            }
        }
    }

    if res == 100005{
        return -1
    }else{
        return res
    }
}

func min(x, y int) int{
    if x <= y{
        return x
    }else{
        return y
    }
}

func minimumCardPickup2(cards []int) int {
    res := len(cards) + 1

    pos := map[int]int{}

    for i, v := range cards{
        if p, ok := pos[v]; ok && i - p + 1 < res{
            res = i - p + 1
        }

        pos[v] = i 
    }

    if res == len(cards) + 1{
        return -1
    }

    return res
}