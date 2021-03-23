n,m = map(int,input().split())
num = list(map(int,input().split()))
num.sort()
visit = [False] * n
li = []

def dfs(cnt):
    if cnt == m:
        print(*li)
        return
    for i in range(n):
        if visit[i] == True:
            continue
        li.append(num[i])
        dfs(cnt+1)
        li.pop()
        visit[i] = True
        for j in range(i+1,n):
            visit[j] = False
dfs(0)