class Solution:
    def cellsInRange(self, s: str) -> List[str]:
        ac, ar = s[0], int(s[1])
        bc, br = s[3], int(s[4])
        res = []
        for i in range(ord(ac), ord(bc)+1):
            for j in range(ar, br+1):
                res.append(chr(i)+str(j))

        return res