# 可以表示 T+1 个状态，因为喝了T瓶没死，还有1瓶说明其有毒
# 信息论 + k进制表示
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        times = minutesToTest // minutesToDie + 1
        return math.ceil(math.log(buckets) / math.log(times))