# 栈
class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        stack.append("")
        i, n = 1, len(path)
        while i < n:
            temp = ""
            while i < n and path[i] != '/':
                temp += path[i]
                i += 1
            while i<n and path[i] == '/':
                i += 1
            if temp == '..':
                if stack[-1] == '':
                    continue
                else:
                    stack.pop()

            elif temp == '.' or temp == '':
                continue

            else:
                stack.append(temp)

            
        if stack[-1] == '':
            return '/'
        else:
            return '/'.join(stack)
