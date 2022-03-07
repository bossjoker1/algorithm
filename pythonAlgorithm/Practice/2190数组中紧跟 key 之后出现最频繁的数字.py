# 字典排序 返回排序后的tuple数组

class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        dic = defaultdict(int)
        for i in range(len(nums) - 1):
            if nums[i] == key:
                dic[nums[i+1]] += 1

        res = sorted(dic.items(), key=lambda kv: -kv[1])
        print(res)
        return res[0][0]
