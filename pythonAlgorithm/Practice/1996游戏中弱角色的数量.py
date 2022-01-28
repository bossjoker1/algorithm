# 一开始看标签 单调栈，但是发现由于攻击力可能相同，所以不是很好处理
# 故还是得按照下面的方法排序才行

# 攻击力降序
# 防御力必须升序，因为同一攻击力下不可能出现弱角色

class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        properties.sort(key=lambda x : (-x[0],x[1]))
        res, maxv = 0, -1
        for item in properties:
            if maxv > item[1]:
                res+=1
            else:
                maxv = item[1]

        return res  
