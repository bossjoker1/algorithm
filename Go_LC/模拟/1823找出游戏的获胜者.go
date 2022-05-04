package main

// 约瑟夫问题，迭代法
func findTheWinner(n int, k int) int {
    if n == 1{
        return 1
    }
    winner := 1
    for i := 2; i <= n; i ++{
        winner = (winner + k - 1) % i + 1
    }

    return winner
}