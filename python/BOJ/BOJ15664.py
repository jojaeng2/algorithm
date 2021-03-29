n,m = map(int,input().split())
num = list(map(int,input().split()))
num.sort()
visit = [False] * n
check = set([])
li = []
def dfs(cnt):
    global li
    if cnt == m:
        li = tuple(li)
        if li not in check:
            check.add(li)
            li = list(li)
            print(*li)
            return
        li = list(li)
        return
    for i in range(n):
        if visit[i] == True:
            continue
        visit[i] = True
        li.append(num[i])
        dfs(cnt+1)
        li.pop()
        for j in range(i+1,n):
            visit[j] = False
dfs(0)