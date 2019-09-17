classMap = {'object':list()}


def find_path(start, end, path = [] ):
    if start not in classMap:
        return None
    path = path + [start]
    if start == end:
        return path
    for node in classMap[start]:
        #if node not in path:
        newpath = find_path(node, end, path)
        if newpath:
                return newpath
    return None


for _ in range(int(input())):
    className, *clss = str(input()).split()
    if className not in classMap:
        classMap[className] = list()
    if len(clss) > 0:
        for i in (clss[1:]):
            if i not in classMap:
                classMap[i] = list()
            classMap[i].append(className)

for _ in range(int(input())):
    classes = str(input()).split()
    if find_path(classes[0], classes[1]) == None:
        print('No')
    else:
        print('Yes')



