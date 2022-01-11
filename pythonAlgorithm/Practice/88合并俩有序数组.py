class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # 从后往前找，直接利用辅助空间
        last = m + n - 1
        while n:
            if m == 0 or nums1[m-1] < nums2[n-1]:
                nums1[last] = nums2[n-1]
                n -= 1
            else:
                nums1[last] = nums1[m-1]
                m -= 1
            last -= 1