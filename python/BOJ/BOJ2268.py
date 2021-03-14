t = int(input())
graph = [i for i in range(t+1)]
log = [0]
for i in range(t):
    log.append(int(input()))

def dfs(a,b,visit):
    if visit[b] == True:
        if graph[b] == a:
            return True
        else:
            return False
    else:
        visit[b] = True
        b = log[b]
        return dfs(a,b,visit)


result = set([])
for i in range(1,t+1):
    visit = [False for j in range(t+1)]
    if dfs(i,i,visit) == True:
        for p in range(1,t+1):
            if visit[p] == True:
                result.add(p)
result = list(result)
print(len(result))
result.sort()
for i in result:
    print(i)