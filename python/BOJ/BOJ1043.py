n,m = map(int,input().split())
li = list(map(int,input().split()))
lie = [True for i in range(n+1)]
graph = [i for i in range(n+1)]
if len(li) > 0:
    for i in range(1,len(li)):
        lie[li[i]] = False
def find(target):
    if target == graph[target]:
        return target
    graph[target] = find(graph[target])
    return graph[target]
def union(x,y):
    x = find(x)
    y = find(y)
    if lie[x] == False:
        graph[y] = graph[x]
    elif lie[y] == False:
        graph[x] = graph[y]
    else:
        if x < y:
            graph[y] = graph[x]
        else:
            graph[x] = graph[y]

result = 0
dat = []
for i in range(m):
    a = list(map(int,input().split()))
    dat.append(a)
    if a[0] > 1:
        for j in range(2,a[0]+1):
            union(a[j],a[j-1])
for i in range(m):
    bl = True
    if len(dat[i]) == 1:
        result += 1
    else:
        for j in range(1,len(dat[i])):
            ans = lie[find(dat[i][j])]
            if ans == False:
                bl = False
                break
    
    if bl == True:
        result += 1
print(result)