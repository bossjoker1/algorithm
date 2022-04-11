# 旧题重做
# 为了满足题目条件，需要额外设置数组保存状态值

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        visited, cnt = [0]*26, [0]*26
        for item in s:
            cnt[ord(item) - ord('a')] += 1
        # 单调栈
        stack = []
        for i in range(len(s)):

            if not visited[ord(s[i]) - ord('a')]:
                while stack and stack[-1] > s[i] and cnt[ord(stack[-1]) - ord('a')] > 0:
                    visited[ord(stack.pop()) - ord('a')] = 0

                stack.append(s[i])
                visited[ord(s[i]) - ord('a')] = 1

            cnt[ord(s[i]) - ord('a')] -= 1 
                
        return ''.join(stack)
