# 因为只调用400次，可以直接差分，然后每次遍历求差分和
class MyCalendarThree:

    def __init__(self):
        self.dic={}


    def book(self, start: int, end: int) -> int:
        if start in self.dic:
            self.dic[start]+=1
        else:
            self.dic[start]=1
        if end in self.dic:
            self.dic[end]-=1
        else:
            self.dic[end]=-1
        f=sorted(self.dic.items(),key=lambda x:x[0])
        cur=0
        cmax=0
        for i in f:
            cur+=i[1]
            cmax=max(cmax,cur)
        return cmax
