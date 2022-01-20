# 递归，写好伴随条件
# 0需要特殊处理一下
# 直接a

class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        self.res = []
        if len(s) > 12:
            return self.res

        def recur(s:str, cnt:int, temp:str):
            # 此次划分不合要求，加快收敛
            if len(s) > (4-cnt)*3:
                return
            # 满足条件，加入结果数组
            if s == '':
                if cnt == 4:
                    # 不要最后一个.
                    self.res.append(temp[:-1])
                return

            # 当前字符串开头为0，只能将其单独划分为一段
            if s[0] == '0':
                temp = temp + s[0] + '.'
                recur(s[1:], cnt+1, temp)

            else:
                
                if len(s) > 0:
                    # 选一个
                    recur(s[1:], cnt+1, temp + s[0] + '.')

                if len(s) > 1:
                    # 选两个
                    recur(s[2:], cnt+1, temp + s[0:2] + '.')

                if len(s) > 2 and int(s[0:3]) <= 255:
                    # 选三个
                    recur(s[3:], cnt+1, temp + s[0:3] + '.')

        recur(s, 0, "")

        return self.res
        
        

            




            

