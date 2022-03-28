# 求椭圆和直线围的面积？woc
# 椭圆面积公式: pai * 长半轴 * 短半轴
import math
class Line:
    def __init__(self,a,b,start,end):
        self.a=a
        self.b=b
        self.start=start
        self.end=end
    
class Solution:
    #输入：输入第第一行包含五个整数，分别为XA,YA,XB,YB,L
    # 第二行包含六个整数：分别为x1,y1,x2,y2,x3,y3

    #输出：
    # 输出一行，包含一个实数，四舍五入保留2位小数，表示答案
    def desertIsland(self,tance,triangle):
        #1.求出椭圆方程的a,b,c。并且知道x*2/a*2+y*2/b*2=1
        a=tance[4]/2
        c=math.sqrt((tance[0]-tance[2])**2+(tance[1]-tance[3])**2)/2
        b=math.sqrt(a**2-c**2)
        #2.进行坐标轴的变换，先进行坐标轴的平移，然后进行坐标轴的旋转
        #坐标轴逆时针旋转a°，则新的坐标位x=Xcosa+Ysina,y=Ycosa-Xsina
        horn=math.atan((tance[3]-tance[1])/(tance[2]-tance[0]))
        O_offset=((tance[0]+tance[2])/2,(tance[1]+tance[3])/2)
        p1_temp=(triangle[0]-O_offset[0],triangle[1]-O_offset[1])
        p2_temp=(triangle[2]-O_offset[0],triangle[3]-O_offset[1])
        p3_temp=(triangle[4]-O_offset[0],triangle[5]-O_offset[1])

        p1_new=(p1_temp[0]*math.cos(horn)+p1_temp[1]*math.sin(horn),-p1_temp[0]*math.sin(horn)+p1_temp[1]*math.cos(horn))
        p2_new=(p2_temp[0]*math.cos(horn)+p2_temp[1]*math.sin(horn),-p2_temp[0]*math.sin(horn)+p2_temp[1]*math.cos(horn))
        p3_new=(p3_temp[0]*math.cos(horn)+p3_temp[1]*math.sin(horn),-p3_temp[0]*math.sin(horn)+p3_temp[1]*math.cos(horn))
        
        #3.x从-a到a，计算每一个小矩形的面积。然后累加得到答案
        #3.1计算x_start,x_end
        #3.2计算出三条直线的方程，并且存储
        #3.3将积分计算出答案
        x_start=max(-a,min(p1_new[0],p2_new[0],p3_new[0]))
        x_end=min(a,max(p1_new[0],p2_new[0],p3_new[0]))
        lines=list()
        #求a1,b1
        a1_parent=(p2_new[0]-p1_new[0])
        if a1_parent:
            a1=(p2_new[1]-p1_new[1])/a1_parent
            b1=p1_new[1]-a1*p1_new[0]
            start1=min(p1_new[0],p2_new[0])
            end1=max(p1_new[0],p2_new[0])
            line1=Line(a=a1,b=b1,start=start1,end=end1)
            lines.append(line1)


        #求a2,b2
        a2_parent=(p3_new[0]-p2_new[0])
        if a2_parent:
            a2=(p3_new[1]-p2_new[1])/a2_parent
            b2=p2_new[1]-a2*p2_new[0]
            start2=min(p2_new[0],p3_new[0])
            end2=max(p2_new[0],p3_new[0])
            line2=Line(a=a2,b=b2,start=start2,end=end2)
            lines.append(line2)


        #a3,b3
        a3_parent=(p1_new[0]-p3_new[0])
        if a3_parent:
            a3=(p1_new[1]-p3_new[1])/a3_parent
            b3=p3_new[1]-a3*p3_new[0]
            start3=min(p1_new[0],p3_new[0])
            end3=max(p1_new[0],p3_new[0])
            line3=Line(a=a3,b=b3,start=start3,end=end3)
            lines.append(line3)

        x=x_start
        res=0
        step=0.001
        while x<=x_end:
            temp=[]
            for i,line in enumerate(lines):
                if line.start<=x and line.end>=x:
                    temp.append(x*line.a+line.b)
            temp_big=max(temp[0],temp[1])
            temp_little=min(temp[0],temp[1])
            tuoyuan_temp=math.sqrt((1-(x**2)/(a**2))*(b**2))
            y_big=min(temp_big,tuoyuan_temp)
            y_little=max(temp_little,-tuoyuan_temp)
            if y_big>=y_little:
                res+=step*(y_big-y_little)
            x+=step   
        return round(res,2)
    
if __name__=='__main__':
    solution=Solution
    tance=list(map(int,input().split()))
    triangle=list(map(int,input().split()))

    result=solution.desertIsland(solution,tance,triangle)
    print(result)
