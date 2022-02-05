class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        less, great, equal = [], [], []
        for item in nums:
            if item < pivot:
                less.append(item)
            elif item > pivot:
                great.append(item)
            else:
                equal.append(item)
                
        less.extend(equal)
        less.extend(great)
        
        return less