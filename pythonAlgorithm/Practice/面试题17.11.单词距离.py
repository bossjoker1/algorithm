# hash表 + 双指针

class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        mp = defaultdict(list)
        for i in range(len(words)):
            mp[words[i]].append(i)

        l, r = 0, 0
        m, n = len(mp[word1]), len(mp[word2])
        temp1, temp2 = mp[word1], mp[word2]
        minn = 100005

        while l < m and r < n:
            minn = min(minn, abs(temp1[l] - temp2[r]))

            if temp1[l] >= temp2[r]:
                r += 1
            else:
                l += 1

        return minn
        