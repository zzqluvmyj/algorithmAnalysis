men = [
    {
        "name": "a",
        "dream": ['e', 'f', 'g', 'h'],
        "mate":""
    },
    {
        "name": "b",
        "dream": ['f', 'g', 'h', 'e'],
        "mate":""
    },
    {
        "name": "c",
        "dream": ['g', 'e', 'h', 'f'],
        "mate":""
    },
    {
        "name": "d",
        "dream": ['h', 'e', 'f', 'g'],
        "mate":""
    }
]
women = [
    {
        "name": "e",
        "dream": ['d', 'a', 'c', 'b'],
        "mate":""
    },
    {
        "name": "f",
        "dream": ['c', 'd', 'a', 'b'],
        "mate":""
    },
    {
        "name": "g",
        "dream": ['b', 'a', 'c', 'd'],
        "mate":""
    },
    {
        "name": "h",
        "dream": ['a', 'b', 'd', 'c'],
        "mate":""
    }
]


def compare(woman, man, singledogs):#比较并决定是否抛弃配偶
    if(woman["dream"].index(woman["mate"]) > woman["dream"].index(man["name"])):
        singledogs.append(woman["mate"])
        return True
    else:
        return False

#初识的单身狗们
singledogs = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']

while(singledogs):#当还存在单身狗，则继续循环
    for man in men:#对于每个男人
        for dreamer in man["dream"]:#那么他将按照先后顺序依次向女士求婚
            if man["name"] not in singledogs:#如果这个男人不是单声狗，则没必要继续求婚
                break
            for woman in women:##对于每个女人
                if(woman["name"] == dreamer):#如果他找到了这个女人
                    if(woman["mate"]==""):#女人未婚，他们美好的生活
                        woman["mate"] = man["name"]
                        man["mate"] = woman["name"]
                        singledogs.remove(man["name"])
                        singledogs.remove(woman["name"])
                        break
                    elif(compare(woman, man, singledogs)):#如果已婚，女人进行比较，淘汰不喜欢的人
                        singledogs.remove(man["name"])
                        break
                    else:
                        pass#如果女人已婚而且被该女人淘汰，则寻找下一个女人
print("men:women")                 
for man in men:
    print(man["name"]+":"+man["mate"])
for woman in women:
    print(woman["name"]+":"+woman["mate"])