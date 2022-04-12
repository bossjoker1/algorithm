class Solution:
    def maxNumber(self, nums1, nums2, k):
        # 对两个数组分别求选出最大数
        # 然后对齐结果进行合并拼接，即需要对i, k-i进行枚举
        
        def pick_max(nums, k):
            stack = []
            drop = len(nums) - k
            for num in nums:
                while drop and stack and stack[-1] < num:
                    stack.pop()
                    drop -= 1
                stack.append(num)
            return stack[:k]

        # 字典序大的排在前面
        def merge(A, B):
            ans = []
            while A or B:
                bigger = A if A > B else B
                ans.append(bigger.pop(0))
            return ans
        
        # 枚举分割位置
        return max(merge(pick_max(nums1, i), pick_max(nums2, k-i)) for i in range(k+1) if i <= len(nums1) and k-i <= len(nums2))