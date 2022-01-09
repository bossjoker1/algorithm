class Solution:
    def capitalizeTitle(self, title: str) -> str:
        l = title.split(" ")
        res = ""
        i = 0;
        for t in l:
            if len(t) == 1 or len(t) == 2:
                res += str(t).lower()
            else:
                temp = str(t)[0].upper() + str(t)[1:].lower()
                res += temp
            if(i != len(l) - 1):
                res += " "
            i += 1
            
        return res