class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        res = []
        n = len(sentence)
        c = sentence.strip().split(' ')
        
        for subs in c:
            if subs[0] != '$' or len(subs) <= 1:
                res.append(subs)
            else:
                flag = True
                for i in range(1, len(subs)):
                    if  ord(subs[i]) < 48 or ord(subs[i]) > 57:
                        res.append(subs)
                        flag = False
                        break
                if flag:
                    nums = int(subs[1:])
                    temp =  '$%.2f'%(nums*(1.0 - 1.0*(discount / 100)))
                    
                    res.append(temp)
                    
        return " ".join(res)
            
        