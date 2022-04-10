# 水题
table = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        res = set()
        for item in words:
            temp = ""
            for i in range(len(item)):
                temp += table[ord(item[i]) - ord('a')]

            res.add(temp)

        return len(res)
