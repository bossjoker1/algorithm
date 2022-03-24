class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        n = len(rooms)
        visited = [0] * n

        def dfs(cur:int):
            if visited[cur]:
                return
            visited[cur] = 1
            for room in rooms[cur]:
                dfs(room)

        dfs(0)

        if visited.count(0) > 0:
            return False
        else:
            return True
