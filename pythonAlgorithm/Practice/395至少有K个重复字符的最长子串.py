class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        return self.dfs(s,k)


    def dfs(self,s,k):
        #字符串为空直接返回0
        if not s:
            return 0
        #遍历s并得到字母与其对应的个数
        cnt = collections.Counter()       
        for i in s:
            cnt[i]+=1
        #初始化最大长度ans与循环字母的计数n
        ans = 0
        n = 0
        #循环cnt判断时候小于k
        for i in cnt:
            if cnt[i] < k:
                #进行字符串的拆分并dfs
                for subs in s.split(i):
                    res = self.dfs(subs,k)
                    #迭代最大值
                    ans = max([ans,res])
                #终止循环cnt
                break
            else:
                n +=1
        #进行最终返回的判断
        return len(s) if n == len(cnt) else ans
