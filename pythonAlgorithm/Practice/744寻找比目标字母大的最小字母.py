# 水的不能再水的题
class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        if letters[-1] <= target:
            return letters[0]

        for i in range(len(letters)):
            if letters[i]>target:
                return letters[i]

        return ""