package main

const MOD int = (1e9 + 7)

// 写复杂了
func countTexts(pressedKeys string) int {
    res, idx, n := 1, 1, len(pressedKeys)
    pre := pressedKeys[0]
    cnt := 1
    for ;idx < n; idx++{
        if pre == pressedKeys[idx]{
            cnt ++
        }
        if (pre != pressedKeys[idx] || idx == n-1){
            // fmt.Println(cnt)
            dp := make([]int , max(4, cnt+1))
            dp[0], dp[1] = 1, 1
            dp[2] = 2
            dp[3] = 4
            if cnt > 3{
                if pre == '7' || pre == '9'{
                    for i := 4 ; i <= cnt; i++{
                        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4]) % MOD
                    }
                }else{
                    for i := 4 ; i <= cnt; i++{
                        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD
                    }
                }
            }
            res = (res * dp[cnt]) % MOD
            cnt = 1
            pre = pressedKeys[idx]
        }
    }
    
    return res
}


func max(x, y int) int{
    if x < y{
        return y
    }else{
        return x
    }
}


// dl写的预处理
const mod, mx int = 1e9 + 7, 1e5

var f = [mx + 1]int{1, 1, 2, 4}
var g = f

func init() {
	for i := 4; i <= mx; i++ { // 预处理所有长度的结果
		f[i] = (f[i-1] + f[i-2] + f[i-3]) % mod
		g[i] = (g[i-1] + g[i-2] + g[i-3] + g[i-4]) % mod
	}
}

func countTexts2(s string) int {
	ans, cnt := 1, 0
	for i, c := range s {
		cnt++
		if i == len(s)-1 || s[i+1] != byte(c) { // 找到一个完整的组
			if c != '7' && c != '9' {
				ans = ans * f[cnt] % mod
			} else {
				ans = ans * g[cnt] % mod
			}
			cnt = 0
		}
	}
	return ans
}
