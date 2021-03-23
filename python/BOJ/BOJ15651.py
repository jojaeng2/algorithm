n,m = map(int,input().split())

num = [i+1 for i in range(n)]
li = []

def dfs(cnt):
    if cnt == m:
        print(*li)
        return
    for i in range(n):
        li.append(num[i])
        dfs(cnt+1)
        li.pop()
dfs(0)