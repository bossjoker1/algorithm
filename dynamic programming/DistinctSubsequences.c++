//115
//1.递归+记忆化搜索
// go实现
func numDistinct(s string, t string) int {
	sLen, tLen := len(s), len(t)

	memo := make([][]int, sLen) // 创建一个memo数组存储计算过的子问题
	for i := range memo {
		memo[i] = make([]int, tLen)
		for j := 0; j < tLen; j++ {
			memo[i][j] = -1
		}
	}
	var helper func(i, j int) int
	helper = func(i, j int) int { // 从开头到s[i]的子串中，出现『从开头到t[i]的子串』的 次数
		if j < 0 { // base case 当j指针越界，此时t为空串，s不管是不是空串，匹配方式数都是1
			return 1
		}
		if i < 0 { // base case i指针越界，此时s为空串，t不是，s怎么也匹配不了t，方式数0
			return 0
		}
		if memo[i][j] != -1 { // 计算过的子问题的解，直接从memo中拿出来返回
			return memo[i][j]
		}
		if s[i] == t[j] { // t[j]被匹配掉，对应helper(i-1, j-1)，不被匹配掉对应helper(i-1, j)
			memo[i][j] = helper(i-1, j) + helper(i-1, j-1)
		} else {
			memo[i][j] = helper(i-1, j) // 
		}
		return memo[i][j] // 返回当前递归子问题的解
	}

	return helper(sLen-1, tLen-1) //从开头到s[sLen-1]的子串中，出现『从开头到t[tLen-1]的子串』的次数
}


//2.动态规划，因为状态只与前一行数据有关所以可以只用一个一维数组来维持，一个一维数组作状态转移
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<long> temp(m+1, 0);
        vector<long> dp(m+1, 0);

        temp[0] = 1;
        dp[0] = 1;

        for(int i = 0;i<n;i++){
            for(int j = 1; j < m+1;j++){
                if(s[i] == t[j-1])
                    dp[j] += temp[j-1];
                temp[j-1] = dp[j-1];
            }
        }

        return dp[m];
    }
};