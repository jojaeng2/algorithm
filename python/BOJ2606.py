n = int(input())
m = int(input())
li = []
visit = [0]*(n+1)
for i in range(n+1):
    li.append([0]*(n+1))
for i in range(m):
    x,y = map(int,input().split())
    li[x][y] = 1
    li[y][x] = 1
def dfs(num):
    visit[num] = 1
    for i in range(1,n+1):
        if visit[i] == 0 and li[num][i] == 1:
            dfs(i)
dfs(1)
print(visit.count(1)-1)
