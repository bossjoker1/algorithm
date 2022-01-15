# 多路归并 堆维护

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        m = len(nums1)
        n = len(nums2)
        # 防止重复，先把nums[i]+nums[0]全部入堆
        # 之后 添加(nums[i] nums[j+1]) 才不会导致有重复元素
        pq = [(nums1[i]+nums2[0], i, 0) for i in range(min(m, k))]
        ans = []
        while pq and len(ans) < k:
            _, i, j = heappop(pq)
            ans.append([nums1[i], nums2[j]])
            if j + 1 < n:
                heappush(pq, (nums1[i]+nums2[j+1], i, j+1))
            
        return ans


