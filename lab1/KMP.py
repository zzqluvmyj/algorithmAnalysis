def getNext(s):
    next = []  # 保存子串的next值
    k = 0  # 匹配串（重复部分）的索引
    i = 1  # 子串字符索引
    next.append(0)  # 初始化为0
    l = len(s)  # 子串长度
    while(i < l):
        # 当有一个字符匹配时，就看接下来的是否匹配，如果否，则后退匹配串，直到重新发现一个匹配或者其他，最后k为0
        while(k > 0 and s[i] != s[k]):
            k = next[k-1]
        if(s[i] == s[k]):  # 如果上一个字符匹配，下一个字符匹配时会增加k，即k是叠加而来
            k = k+1
        next.append(k)  # 每次匹配后，给当前字符的next赋值
        i = i+1
    return next

s1 = input("Please input a string:")
s2 = input("Please input a string to match the former.")
m1 = len(s1)
m2 = len(s2)
next = getNext(s2)
print("The next[] are "+str(next))
i, j = 0, 0
while(i < m1 and m1>=m2):# 当主串指针没有到尾部，主串比子串长时循环继续
    while(j>0 and s1[i] != s2[j]):# 当子串指针大于0时，如果不等，i不变，重新寻找适合子串的指针j
        j=next[j-1]
    if(s1[i]==s2[j]):#如果字符相等，子串指针向后移
        j=j+1
    if(j==m2):  # 判断条件，多次匹配
        print("Matched in the "+str(i+2-m2)+"character.")
        j = 0
    i=i+1#主串指针向后移
