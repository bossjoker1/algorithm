class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        cnt = Counter(tasks)
        
        # print(cnt)
        res = 0
        for k, v in cnt.items():
            if v == 1:
                return -1
            if v % 3 == 0:
                res += v // 3
            if v % 3 != 0:
                res += v // 3 + 1
                
        return res