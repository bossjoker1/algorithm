class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        hashmap = defaultdict(int)
        for i in range(len(list1)):
            hashmap[list1[i]] = i
        minv = 10000
        res = []
        for i in range(len(list2)):
            if list2[i] in hashmap:
                temp = i + hashmap[list2[i]]
                if temp < minv:
                    minv = temp
                    res.clear()
                    res.append(list2[i])
                elif minv == temp:
                    res.append(list2[i])
        return res
