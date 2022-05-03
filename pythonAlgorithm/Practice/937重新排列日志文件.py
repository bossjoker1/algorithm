class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        n = len(logs)
        res1, res2 = [], []
        for sub in logs:
            tmp = sub.strip().split(' ')
            if tmp[1].isdigit():
                res1.append(sub)
            else:
                res2.append(sub)

        res2.sort(key=lambda x : (x.split(' ')[1:], x.split(' ')[0]))

        res2.extend(res1)

        return res2