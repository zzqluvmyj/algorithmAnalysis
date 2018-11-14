# BF算法  蛮力法解决字符串匹配问题
# 获取输入
print("This is a BF algorithm")
mainStr = input("Please enter a main string:")
subStr = input("Please enter a matched string:")
# 求长度
n = len(mainStr)
m = len(subStr)
# 判断字符串是否有效
if(m > n):
    print("The main string should larger than matched string!")
else:
    i = 0  # 主串浮动指针
    j = 0  # 子串浮动指针
    while(i < (n-m+1)):  # 当主串指针已经到n-m+1时，肯定无法匹配
        while(j < m):  # 子串的指针不超过其长度m
            if(mainStr[i] != subStr[j]):  # 如果对应字符不相等，则跳出内循环
                i=i-j+1########################
                j=0
                break
            else:  # 如果相等，继续比较
                i = i+1
                j = j+1
        if(j == m):  # 跳出内循环后测试是否已经完成了匹配
            print("The string are matched in "+str(i-m+1)+"character")
        if(i >= (n-m+1) and j != m):  # 测试当i全部尝试匹配时，j是否没有完成匹配
            print("The string didn't match.")

