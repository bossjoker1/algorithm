package main

import "math"

// 枚举
func largestTriangleArea(points [][]int) float64 {
    // 枚举
    var res float64 = 0.0
    m := len(points)
    for i := 0 ; i < m - 2; i++{
        x1, y1 := points[i][0], points[i][1]
        for j := i + 1; j < m - 1; j ++{
            x2, y2 := points[j][0], points[j][1]

            for k:=j+1; k < m; k++{
                x3, y3 := points[k][0], points[k][1]
                // fmt.Println(x1, y1, x2, y2, x3, y3)
                res = math.Max(math.Abs(float64(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2) /2) , res)
            }
        }
    }
    return res
}