# hash维护区间长度
# 并查集的话，维护最右边界？
# 即每次并到靠右的树上？

class Solution(object):
    def longestConsecutive(self, nums):
        hash_dict = dict()
        
        max_length = 0
        for num in nums:
            if num not in hash_dict:
                left = hash_dict.get(num - 1, 0)
                right = hash_dict.get(num + 1, 0)
                
                cur_length = 1 + left + right
                if cur_length > max_length:
                    max_length = cur_length
                
                hash_dict[num] = "here"
                # 两边开始延申
                hash_dict[num - left] = cur_length
                hash_dict[num + right] = cur_length
                
        return max_length
