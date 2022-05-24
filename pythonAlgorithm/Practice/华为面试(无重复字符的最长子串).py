# 无重复字符的最长子串
# 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

# 示例 1:
# 输入: s = "abcabcbb"
# 输出: 3 
# 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
# 示例 2:

# 输入: s = "bbbbb"
# 输出: 1
# 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
# 示例 3:

# 输入: s = "pwwkew"
# 输出: 3
# 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
#      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

from collections import defaultdict

s = input()
n = len(s)
maxn = 1
mp = [-1] * 26
r = 0

while r < n:
    cur = ord(s[r]) - ord('a')
    if mp[cur] != -1 or r == n - 1:
        maxn = max(maxn, r - mp[cur])
            
    mp[cur] = r        
    r += 1
    
print(maxn)         
        