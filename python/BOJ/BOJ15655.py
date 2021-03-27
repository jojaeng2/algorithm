n,m = map(int,input().split())
num = list(map(int,input().split()))
num.sort()
visit = [False for i in range(n)]
li = []
def dfs(cnt):
    if cnt == m:
         print(*li)
         return
    for i in range(n):
        if visit[i] == True:
            continue
        li.append(num[i])
        visit[i] = True
        dfs(cnt+1)
        li.pop()
        for j in range(i+1,n):
            visit[j] = False
dfs(0)
