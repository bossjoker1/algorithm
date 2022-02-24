# 单调栈 + 哨兵
# 单调栈维护递增序列，如果有比栈顶更矮的柱子说明，左右扩展到了边界，开始退栈

class Solution:

    def largestRectangleArea(self, heights: List[int]) -> int:
        n, heights, st, ans = len(heights),[0] + heights + [0], [], 0
        for i in range(n + 2):
            while st and heights[st[-1]] > heights[i]:
                a = heights[st[-1]]
                st.pop()
                # 如果没有前面的哨兵，这里的 st[-1] 可能会越界。
                ans = max(ans, a * (i - 1 - st[-1]))
            st.append(i)
        return ans