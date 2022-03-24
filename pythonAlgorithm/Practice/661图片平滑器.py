# 二维前缀和

class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])

        preSum = [[0] * (n+1) for _ in range(m+1)]

        for i in range(m):
            for j in range(n):
                preSum[i+1][j+1] = preSum[i+1][j] + preSum[i][j+1] - preSum[i][j] + img[i][j]

        res = [[0] * (n) for _ in range(m)]
        for i in range(m):
            for j in range(n):
                lx, ly = max(0, i-1), max(0, j-1)
                rx, ry = min(m-1, i + 1), min(n-1, j+1)
                cnt = (rx - lx + 1) * (ry - ly + 1)

                res[i][j] = math.floor((preSum[rx+1][ry+1] - preSum[lx][ry+1] - preSum[rx+1][ly] + preSum[lx][ly])/cnt)


        return res