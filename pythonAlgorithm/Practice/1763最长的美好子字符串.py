# 今年一定要美好！！！

# 1. 暴力枚举 + set去重

class Solution:
    def longestNiceSubstring(self, s: str) -> str:

        def check(s : str)->bool:
            n1, n2 = len(set(s)), len(set(s.lower()))
            if n1 == n2*2:
                return True
            else:
                return False

        maxl, n = -1, len(s)
        start, end = 0, 0
        for i in range(n):
            for j in range(i+1, n):
                if check(s[i:j+1]):
                    if j+1-i > maxl:
                        start, end = i, j+1
                        maxl = j+1-i

        return s[start:end]

# 前缀和 依然要枚举，维护子串每个字母大小写是否出现，因此只用二进制即可
# 分别用两个int的低26位表示
# 贴个叶总的java题解

# class Solution {
#     public String longestNiceSubstring(String s) {
#         int n = s.length();
#         int idx = -1, len = 0;
#         for (int i = 0; i < n; i++) {
#             int a = 0, b = 0;
#             for (int j = i; j < n; j++) {
#                 char c = s.charAt(j);
#                 if (c >= 'a' && c <= 'z') a |= (1 << (c - 'a'));
#                 else b |= (1 << (c - 'A'));
#                 if (a == b && j - i + 1 > len) {
#                     idx = i; len = j - i + 1;
#                 }
#             }
#         }
#         return idx == -1 ? "" : s.substring(idx, idx + len);
#     }
# }
