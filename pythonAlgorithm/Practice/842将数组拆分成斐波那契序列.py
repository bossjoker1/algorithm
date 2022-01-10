class Solution:
    def splitIntoFibonacci(self, num: str) -> List[int]:

        n = len(num)
        if n < 3:
            return False

        def check(p1, p2, j, tempL):
            while j < n:
                p = str(int(p1) + int(p2))
                # 题目限制，麻了
                if num[j: j+len(p)] != p or int(p) >= 2 **31:
                    return False, []
                j += len(p)
                L.append(int(p))
                # 向前分割
                p1, p2 = p2, p
            return True, L

        # 题目限制遇到0开头，该数就只能是0
        for i in range(1, n//2+1) if num[0] != "0" else [1]:
            for j in range(i+1, n) if num[i] != "0" else [i+1]:
                L = [] 
                p1 = num[:i]
                p2 = num[i:j]
                L.append(int(p1))
                L.append(int(p2))
                flag, tempL = check(p1, p2, j, L)
                if flag:
                    return tempL

        return []

# java：回溯版本
# class Solution {
#     int len;
#     public List<Integer> splitIntoFibonacci(String S) {
#         len = S.length();
#         List<Integer> res = new ArrayList<>();
#         return dfs(0, S, res) ? res : new ArrayList<>();
#     }

#     private boolean dfs(int p, String S, List<Integer> res) {
#         int size = res.size();
#         if (p == len) {
#             return size > 2;
#         }
#         int num = 0;
#         for (int i = p; i < len; i ++) {
#             num = 10 * num + S.charAt(i) - '0';
#             //判断是否溢出
#             if (num < 0) {
#                 return false;
#             }
#             if (size < 2 || num == res.get(size -1) + res.get(size -2)) {
#                 res.add(num);
#                 if (dfs(i + 1, S, res)) {
#                     return true;
#                 }
#                 res.remove(size);
#             }
#             //判断是否以0开头，阻止循环到下一位
#             if (S.charAt(i) - '0' == 0 && i == p) {
#                 return false;
#             }
#         }
#         return false;
#     }
# }
