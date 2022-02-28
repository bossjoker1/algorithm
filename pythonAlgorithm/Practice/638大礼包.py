from functools import lru_cache
# 究极背包问题
class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        # list不能生成hash,所以参数转为tuple
        @lru_cache(None)
        def dfs(remains):
            # 计算单独买要多少钱
            ans = sum(r*price[i] for i,r in enumerate(remains))
            if ans:
                # 遍历找满足要求的礼包
                for ssp in special:
                    check = True
                    for i in range(len(remains)):
                        if ssp[i] > remains[i]:
                            check = False
                            break
                    if check:
                        new = list(remains)
                        # 更新买了礼包后的needs，加上买礼包的钱
                        for i in range(len(remains)):
                            new[i] -= ssp[i]
                        ans = min(ans, dfs(tuple(new)) + ssp[-1])
            return ans
        
        return dfs(tuple(needs))
