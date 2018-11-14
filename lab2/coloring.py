#图着色问题，回溯法
n=5#表示有5个节点
a,b,c,d,e=[0,1,2,3,4]
#节点的邻接节点
graph=[
    {b,c},
    {a,c,d,e},
    {a,b,e},
    {b,e},
    {d,b,c}
]
m=4#颜色数
x=[0]*n#一个解
#冲突检测函数
def conflict(k):
    global n,graph
    nodes=[node for node in range(k) if node in graph[k]]#找到已经涂色的邻接节点
    if x[k] in [x[node] for node in nodes]:#如果已经涂色的邻接节点色彩冲突，返回True
        return True
    return False
def dfs(k):
    global n,m,graph,x
    if k==n:#如果已经超过了第5个节点，则停止继续寻找并输出节点的涂色结果
        print(x)
    else:
        for color in range(m):#寻找一种颜色，涂在k节点上
            x[k]=color
            if not conflict(k):#如果没有冲突，深入下一层，如果有冲突，不再继续往下深入，剪去该分支
                dfs(k+1)
dfs(a)
