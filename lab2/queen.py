def conflict(A,cur,col):
    for r in range(cur):
        if A[r]==col or r-A[r]==cur-A[cur] or r+A[r]==cur+A[cur]:#不能在同一纵行，不能在同一斜线上，如果在则退出循环
            return True
    return False
        
def queen(A, cur=0):
    if cur==len(A):
        print(A)
    else:
        for col in range(len(A)):
            A[cur] = col #表示把第cur行的皇后放在col列上
            if not conflict(A,cur,col):
                queen(A, cur+1)
queen([None]*8)