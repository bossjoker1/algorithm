# 数论
# 关键是思考 因数 之间的关系

# 学习下枚举n及n以下的每个数的因子
n = 10000
divides = []
for i in range(1, n+1):
    for j in range(i, n+1, i):
         divides[j].append(i)


class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        divisors = []  
        d = 1
        while d * d <= k:  # 预处理 k 的所有因子
            if k % d == 0:
                divisors.append(d)
                if d * d < k:
                    divisors.append(k / d)
            d += 1
        ans = 0
        cnt = defaultdict(int)
        for v in nums:
            # 得到smallest数的个数
            ans += cnt[k / gcd(v, k)]
            for d in divisors:
                if v % d == 0:
                    cnt[d] += 1
        return ans