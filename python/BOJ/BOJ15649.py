n,m = map(int,input().split())

num = [i+1 for i in range(n)]
visit = [False] * n
array = []

def dfs(cnt):
    if cnt == m:
        print(*array)
        return
    for i in range(n):
        if visit[i] == True:
            continue
        visit[i] = True
        array.append(num[i])
        dfs(cnt+1)
        array.pop()
        visit[i] = False
dfs(0)