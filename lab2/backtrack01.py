# 回溯法求01背包问题
w=[7,3,4,5]
v=[42,12,40,25]
bag=[]
allv=0
allw=0
def backtrack(k):
    global allv,allw,w,v
    if(k==4):
        if(allw<=10):#如果到达最后，并且没有超过10，则输出总价值和总重量
            print(allv,allw)
    else:
        for i  in [0,1]:
            if(i==1):#选择k对应的该值，进入左节点，如从节点退出，则相应的撤销操作，实现回溯
                allv+=v[k]
                allw+=w[k]
                backtrack(k+1)#
                allv-=v[k]
                allw-=w[k]
            else:#不选择该值，继续递归加深
                backtrack(k+1)
backtrack(0)

                
                



