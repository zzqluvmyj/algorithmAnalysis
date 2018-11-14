# 0/1背包问题 

# 初始化物品的重量和价值，0,0表示未选中时的重量和价值
item1=[[0,0],[7,42]]
item2=[[0,0],[3,12]]
item3=[[0,0],[4,40]]
item4=[[0,0],[5,25]]

MAX=10 #背包最大重量
son=[] #所能容纳的背包的子集
no=0 #挨个测试的序号

# 增加背包子集
def addson(a,b,c,d,s):
    if(a!=0):
        s.append(1)
    if(b!=0):
        s.append(2)
    if(c!=0):
        s.append(3)
    if(d!=0):
        s.append(4)

# 主程序，穷举测试每种情况
for i in range(2):
    for j in range(2):
        for k in range(2):
            for l in range(2):
                sumH=item1[i][0]+item2[j][0]+item3[k][0]+item4[l][0]
                if(sumH < MAX):
                    sumM=item1[i][1]+item2[j][1]+item3[k][1]+item4[l][1]
                    addson(i,j,k,l,son)
                    print(i,j,k,l)
                else:
                    sumM="不可行"
                no=no+1
                print(no,son,sumH,sumM)
                son.clear()


