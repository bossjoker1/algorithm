# 实际上还需要二分，以每个abs值为标准测试能否达到
class Solution:
    def minSumSquareDiff(self, a: List[int], nums2: List[int], k1: int, k2: int) -> int:
        ans, k = 0, k1 + k2
        for i in range(len(a)):
            a[i] = abs(a[i] - nums2[i])
            ans += a[i] * a[i]
        if sum(a) <= k:
            return 0  # 所有 a[i] 均可为 0
        a.sort(reverse=True)
        a.append(0)  # 哨兵
        for i, v in enumerate(a):
            ans -= v * v
            j = i + 1
            c = j * (v - a[j])
            if c < k:
                k -= c
                continue
            v -= k // j
            return ans + k % j * (v - 1) * (v - 1) + (j - k % j) * v * v



# 超时解，没注意k的范围
class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        diff = [ -abs(x-y) for x, y in zip(nums1, nums2)]
        heapq.heapify(diff)
        cnt = k1 + k2
        for _ in range(cnt):
            temp = - heapq.heappop(diff)
            if temp == 0:break
            temp -= 1
            heapq.heappush(diff, -temp)
        
        return sum([ x * x for x in diff ])