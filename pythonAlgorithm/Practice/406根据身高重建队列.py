# O(n^2)
# 贪心
# 从低到高排序，每一次能确定最矮的人在当前空位下的位置
# 相同高度的，k大的先找
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        n = len(people)
        people.sort(key=lambda x: (x[0], -x[1]))
        
        res = [[] for _ in range(n)]

        for i in range(n):
            k = 0
            for j in range(n):
                if res[j] != []:
                    continue
                if k == people[i][1]:
                    res[j] = people[i].copy()
                    break
                k += 1    
        return res