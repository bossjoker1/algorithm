class Solution:
    def partitionLabels(self, S: str) -> List[int]:
        #存储某个字母对应地最后一个序号
        dic = {s: index for index, s in enumerate(S)}   
        num = 0  #直接计数
        result = []
        j = dic[S[0]]  #第一个字符的最后位置

        for i in range(len(S)):  #逐个遍历
            num += 1  #找到一个就加1个长度
            if dic[S[i]] > j:  #思路一样，如果最后位置比刚才的大，就更新最后位置
                j = dic[S[i]]
            if i == j: 
                # 此时说明这一段为符合要求的一段了，可以划分
                result.append(num)  # 加入result
                num = 0 # 归0
        return result
