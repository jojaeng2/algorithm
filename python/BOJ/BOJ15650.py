n,m = map(int,input().split())

num = [i+1 for i in range(n)]
visit = [False] * n
li = []

def dfs(cnt):
    if cnt == m:
        print(*li)
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
