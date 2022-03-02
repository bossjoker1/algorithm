points = []

for i in range(20):
    for j in range(21):
        points.append((i, j))
        
Lines = []

def isSame(p1, p2) -> bool:
    x1, y1 = p1
    x2, y2 = p2
    for tp1, tp2 in Lines:
        x3, y3 = tp1
        x4, y4 = tp2
        if x2 == x1 and x3 == x4:
            if x1 == x3:
                return True
        elif (x1 != x2 and x3 != x4) and abs((y2 - y1) / (x2 - x1) - (y4 - y3) / (x4 - x3)) < 1e-6 and abs((y4 - y3) * (x1 - x3 )/ (x4 - x3) + y3 - y1) < 1e-6:
            return True
    return False
ans = 0
for i in range(len(points)):
    for j in range(i+1, len(points)):
        if not isSame(points[i], points[j]):
           ans += 1
           Lines.append([points[i], points[j]])

# 40257 跑了5分钟...
print(ans)