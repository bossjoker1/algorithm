# 指路84
# 将矩形拆分成一组组柱状图

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

    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if len(matrix) == 0:
            return 0
        m, n = len(matrix), len(matrix[0])

        heights = [0] * (n)
        maxs = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == "1":
                    heights[j] += 1
                else:
                    heights[j] = 0
            # print(heights)
            maxs = max(maxs, self.largestRectangleArea(heights))

        return maxs