class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        n = len(arr)

        arr.sort(key=lambda x : abs(x))
        print(arr)
        mp = defaultdict(int)

        for i in range(n):
            mp[arr[i]] += 1

        for i in range(n):
            if mp[arr[i]] > 0:
                if mp[arr[i] * 2] > 0:
                    mp[arr[i] * 2] -= 1
                    mp[arr[i]] -= 1
                else:
                    return False

        return True