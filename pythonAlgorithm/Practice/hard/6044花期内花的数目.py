# 直接秒杀
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        n = len(flowers)
        pre, post = [], []
        res = []
        for s, e in flowers:
            pre.append(s)
            post.append(e)
        pre.sort()
        post.sort()

        for t in persons:
            s = bisect_right(pre, t)
            e = bisect_left(post, t)
            res.append(s - e)
        
        return res