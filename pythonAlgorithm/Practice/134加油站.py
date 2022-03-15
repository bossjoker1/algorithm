class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        s, run = 0, 0
        start = 0
        for i in range(len(gas)):
            run += (gas[i] - cost[i])
            s += (gas[i] - cost[i])
            if run < 0:
                start = i+1
                run = 0

        return -1  if s < 0 else start 
            
