# 警卫问题 回溯法
m=int(input("请输入行数："))
n=int(input("请输入列数："))
table=[]
table=[[0 for i in range(n)] for j in range(m)]
num,i,j,k,M=0,0,0,0,999
#其中num是警卫数，i，j,k是为了定位节点的变量
#9代表警卫，其他代表警卫视野
def full():
    global table
    for row in table:
        for col in row:
            if(col==0):
                return False
    return True
def printTable():#打印出表格
    global table
    for row in table:
        print(row)
def addition(row,col):#每个警卫能够监视的周围情况
    global table
    if(row-1>=0):
        table[row-1][col]+=1
    if(row+1<m):
        table[row+1][col]+=1
    if(col-1>=0):
        table[row][col-1]+=1
    if(col+1<n):
        table[row][col+1]+=1
def decrease(row,col):#回溯后退时的操作
    global table
    if(row-1>=0):
        table[row-1][col]-=1
    if(row+1<m):
        table[row+1][col]-=1
    if(col-1>=0):
        table[row][col-1]-=1
    if(col+1<n):
        table[row][col+1]-=1
def conflict(row,col):#警卫是否有冲突
    global table
    if(table[row][col]>=1):
        return True
    else:
        return False
def search(i,j,k):#主函数，遍历节点并且寻找合适的警卫安排
    global table,num,m,n,M
    if(i==m-1 and j<n):#最后一行节点的遍历
        if(not conflict(i,j)):
            for e in range(2):
                if(e==1):
                    table[i][j]+=9
                    addition(i,j)
                    num+=1
                    search(i,j+1,k)
                    table[i][j]-=9
                    decrease(i,j)
                    num-=1
                else:
                    search(i,j+1,k)
        else:
                search(i,j+1,k)
    elif(i<m and j==n-1):#换行继续遍历节点
        t1=i
        t2=j
        k+=1
        i=k
        j=0
        if(not conflict(t1,t2)):
            for e in range(2):
                if(e==1):
                    table[t1][t2]+=9
                    addition(t1,t2)
                    num+=1
                    search(i,j,k)
                    table[t1][t2]-=9
                    decrease(t1,t2)
                    num-=1
                else:
                    search(i,j,k)
        else:
            search(i,j,k)
    elif(i<m and j<n):#当i<m and j<n即，在i行时，递加j，j=n-1时跳出
        if(not conflict(i,j)):
            for e in range(2):
                if(e==1):
                    table[i][j]+=9
                    addition(i,j)
                    num+=1
                    search(i,j+1,k)
                    table[i][j]-=9
                    decrease(i,j)
                    num-=1
                else:
                    search(i,j+1,k)
        else:
            search(i,j+1,k)
    elif(i==m-1 and j==n):#如果全部遍历完毕，输出并退出程序
        if(full()):
            if(M>=num):
                M=num
                print("警卫数： "+str(num))
                for row in table:
                    print(row)
            else:
                pass
            
            
search(i,j,k)
print("最少警卫是"+str(M))

