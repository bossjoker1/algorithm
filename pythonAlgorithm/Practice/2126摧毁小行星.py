# 服了，什么sb题目
class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for n in range(len(asteroids)):
            if mass < asteroids[n]:
                return False
            mass += asteroids[n]
        return True
    
# 感觉没啥问题，但是超时了

class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        def search(nums: List[int], target: int) -> int:
            left, right = 0, len(nums)-1
            while left <= right:
                mid = left + right >> 1
                if target >= nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1
            return left

        asteroids.sort(reverse=True)
        while asteroids:
            idx = search(asteroids, mass)
            if idx < 0 or idx >= len(asteroids):
                return False
            else:
                mass += asteroids[idx]
                del asteroids[idx]

        return True
