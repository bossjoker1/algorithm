package main

func oneEditAway(first string, second string) bool {
    m, n := len(first), len(second)
    if abs(m - n) > 1{
        return false
    }

    if m > n{
        return oneEditAway(second, first)
    }

    i, j, flag := 0, 0, true

    for i < m && j < n{
        c1, c2 := first[i], second[j]

        if c1 == c2{
            i++
            j++
        }else{
            if m == n{
                if !flag{
                    return false
                }else{
                    i++
                    j++
                    flag = false
                }
            }else{
                if !flag{
                    return false
                }else{
                    j++
                    flag = false
                }
            }
        }
    }

    return true
}

func abs(x int) int{
    if x < 0{
        return -x
    }else{
        return x
    }
}