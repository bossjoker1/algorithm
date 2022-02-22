# 怎么也是水题？
class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        if finalSum % 2:
            return []

        res, tempsum = [], 0
        i = 2
        while tempsum <= finalSum:
           tempsum += i
           res.append(i)
           i += 2

        delE = tempsum - finalSum
        if delE == 0:
            return res 
        else:
            res.remove(delE)
            return res            
        