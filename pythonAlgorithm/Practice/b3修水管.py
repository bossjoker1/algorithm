# 给你个矩阵和一个最大Value，矩阵上的值代表着修完这个格子需要花费的值
# 你从(0, 0)开始修，不能往回修，但是必须从矩阵边界修出来(相当于要通往外面)，请选择能修的最长的路径
# 如果修不出来，即没有合适路径，返回-1

# md 当时sb牛客抽风

N, W = list(map(int, input().split()))

g = []

for i in range(N):
    temp = list(map(int, input().split()))
    g.append(temp)
    
dir = [(1, 0), (-1, 0),  (0, 1), (0, -1)]


visited = [[0] * N for _ in range(N)]

res = 0
res_path = []

def dfs(x, y, step, val, tpath):
    global res, res_path
    if val - g[x][y]  < 0:
        return
    step += 1
    val -= g[x][y]
    if x in [0, N-1] or y in [0, N-1]:
        if res < step:
            res = step
            res_path = tpath.copy()
        
    for dx, dy in dir:
        nx, ny = x + dx, y + dy
        if 0<=nx<N and 0<=ny<N and not visited[nx][ny]:
            visited[nx][ny] = 1
            tpath.append(g[nx][ny])
            dfs(nx, ny, step, val, tpath)
            visited[nx][ny] = 0
            tpath.pop()


if g[0][0] > W:
    print(-1)
    
visited[0][0] = 1
dfs(0, 0, 0, W, [g[0][0]])
print("path: ", res_path)
print("maxstep:", res)