class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        # 得到在[1, n]中以prefix为前缀的个数
        # 怎么求？=> 用下一个前缀的个数减去当前前缀的个数
        # eg: 13中以1为前缀的个数 => 下一个前缀为2 所以第一层有 2 - 1 = 1个，第二层 min(13 + 1, 20) - 10 = 4个 所以共5个 
        def getCnt(prefix, n):
            cnt, cur, next = 0, prefix, prefix + 1
            while cur <= n:
                # 需考虑不是满叉树的情况
                cnt += min(next, n + 1) - cur
                # 移到下一层
                cur, next = cur * 10, next * 10
            return cnt
        
        poi, prefix = 1, 1
        while poi < k:
            cnt = getCnt(prefix, n)
            # 第k个在当前前缀的子节点下
            # poi+1移到第一个子节点
            if poi + cnt > k:
                prefix *= 10
                poi += 1
            # 说明在后一个前缀中，此时该前缀的所有节点全部算上，poi移到后面前缀的根节点
            else:
                prefix += 1
                poi += cnt
        return prefix
