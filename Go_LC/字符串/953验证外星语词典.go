package main

func isAlienSorted(words []string, order string) bool {
    mp := map[byte]int{}
    for i := range order {
        mp[order[i]] = i
    }
    for i := 0; i < len(words) - 1; i++ {
        for j := 0; j < len(words[i]); j++ {
            if j == len(words[i + 1]) {
                return false
            }
            if diff := mp[words[i][j]] - mp[words[i + 1][j]]; diff > 0 {
                return false
            } else if diff < 0 {
                break
            }
        }
    }
    return true
}

