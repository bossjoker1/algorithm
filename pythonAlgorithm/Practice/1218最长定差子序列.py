# hash表
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        hashmap = defaultdict(int)
        n = len(arr)
        res = 0

        for i in range(n):
            hashmap[arr[i]] = hashmap[arr[i] - difference] + 1
            res = max(hashmap[arr[i]], res)

        return res    