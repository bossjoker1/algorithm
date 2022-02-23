# 优先队列
# 左边进就加，右边出就删
# 高度变了就加到结果数组

# 做过了，优先队列问题
from sortedcontainers import SortedList


class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        ans = []
        changes = []
        for left, right, height in buildings:
            changes.append((left, -height))
            changes.append((right, height))
        # 按变化点的先后排序
        changes.sort()
        # 同样默认有个高度为0
        lives = SortedList([0])
        # 上一个建筑最高高度
        prev = 0
        for x, h in changes:
            # 根据h大小加入或删除建筑
            if h < 0:
                lives.add(h)
            else:
                lives.remove(-h)
            # 加入或删除后当前的最高高度
            curr_max = -lives[0]
            # 最高高度发生了变化
            if curr_max != prev:
                ans.append([x, curr_max])
            prev = curr_max
        return ans