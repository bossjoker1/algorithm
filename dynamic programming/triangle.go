func minimumTotal(triangle [][]int) int {
	l := len(triangle)
	dp := make([]int, l)
	dp[0] = triangle[0][0]
	for i := 1; i < l; i++ {
		dp[i] = dp[i-1] + triangle[i][i]
		// 这里索引遍历必须是从大到小，否则计算(i, j)，0--j-1此时代表的是dp[i][j]，所以会在[i][j-1]和[i-1][j-1]中选择
		for j := i - 1; j > 0; j-- {
			dp[j] = min(dp[j], dp[j-1]) + triangle[i][j]
		}
		dp[0] += triangle[i][0]
	}

	ans := math.MaxInt32
	for i := 0; i < l; i++ {
		ans = min(ans, dp[i])
	}
	return ans
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}