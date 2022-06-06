# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
plt.rcParams['font.sans-serif']=['Arial']#如果要显示中文字体，则在此处设为：SimHei
plt.rcParams['axes.unicode_minus']=False#显示负号

x = np.array([3,5,7,9,11,13,15,17])
A = np.array([0.1532, 0.1312, 0.1065, 0.0983, 0.1234, 0.1342, 0.1124, 0.3512])
B= np.array([0.0692, 0.0667, 0.0108, 0.0318, 0.0234, 0.0256, 0.0204, 0.0162])
C=np.array([0.0692, 0.0667, 0.0261, 0.0551, 0.0397, 0.0328, 0.0476, 0.0162])


#label在图示(legend)中显示。若为数学公式，则最好在字符串前后添加"$"符号
#color：b:blue、g:green、r:red、c:cyan、m:magenta、y:yellow、k:black、w:white、、、
#线型：-  --   -.  :    ,
#marker：.  ,   o   v    <    *    +    1
plt.figure(figsize=(10,5))
plt.grid(linestyle = "--") #设置背景网格线为虚线
ax = plt.gca()
ax.spines['top'].set_visible(False) #去掉上边框
ax.spines['right'].set_visible(False) #去掉右边框

plt.plot(x,A,color="black",label="One",linewidth=1.5)
plt.plot(x,B,"k--",label="All",linewidth=1.5)
plt.plot(x,C,color="red",label="Weighting",linewidth=1.5)

group_labels=['zbs','cza','xqf','ysy','zyt','cqh','ykh','lh'] #x轴刻度的标识
plt.xticks(x,group_labels,fontsize=12,fontweight='bold') #默认字体大小为10
plt.yticks(fontsize=12,fontweight='bold')
plt.ylabel("FRR",fontsize=13,fontweight='bold')
plt.xlim(2,21) #设置x轴的范围
#plt.ylim(0.5,1)

#plt.legend()          #显示各曲线的图例
plt.legend(loc=0, numpoints=1)
leg = plt.gca().get_legend()
ltext = leg.get_texts()
plt.setp(ltext, fontsize=12,fontweight='bold') #设置图例字体的大小和粗细

plt.savefig('D:\\filename.png') #建议保存为svg格式，再用inkscape转为矢量图emf后插入word中
plt.show()
