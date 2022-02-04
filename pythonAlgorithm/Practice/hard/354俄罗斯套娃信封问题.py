# 感觉做过这个题，忘记在哪了
# python的动规过不了....
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key=lambda x: x[0])
        n = len(envelopes)
        dp = [1] * (n+1)

        for i in range(n):
            for j in range(i):
                wi, hi = envelopes[i]
                wj, hj = envelopes[j]
                if wi > wj and hi > hj:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)
    
# 二分
class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        # 首先知道有几个信封，维护一个动态数组，tails[k]代表最多k+1个信封的末尾元素
        # 贪心：要使得末尾尽量为较小的信封，这样才能放置更多的信封
        n = len(envelopes)
        tails, res = [[0, 0] for _ in range(n)], 0
        # 要保证对于每个w值，最多智能选择一个信封，因此可以将w升序，再将h作为第二关键字进行降序排列
        # 这样对于每个w值，都会选择满足要去的最小的一个h所对应的信封
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        # 对所有的信封进行遍历
        for envelope in envelopes:
            l, r = 0, res
            # 二分查找末尾可以放置的最小信封
            while l < r:
                mid = (l + r) // 2
                if tails[mid][0] < envelope[0] and tails[mid][1] < envelope[1]:
                    l = mid + 1
                else:
                    r = mid
            tails[l] = envelope
            if r == res: res += 1
        return res
