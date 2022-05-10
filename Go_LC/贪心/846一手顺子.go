package main

import (
	"sort"
)

func isNStraightHand(hand []int, groupSize int) bool {
    n := len(hand)
    cnt := map[int]int{}
    if n % groupSize != 0{
        return false
    }

    for _ , i:= range hand{
        cnt[i] ++
    }

    sort.Ints(hand)

    for _,  i := range hand{
        if cnt[i] > 0{
            for j := i; j < i + groupSize; j++{
                if cnt[j] == 0{
                    return false
                }
                cnt[j] --
            }
        }
    }

    return true
}