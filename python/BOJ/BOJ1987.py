import sys
input = sys.stdin.readline
n,m = map(int,input().split())
graph = []
for i in range(n):
    a = list(map(str,input()))
    graph.append(a)

dx = [-1,1,0,0]
dy = [0,0,-1,1]
cnt = 0
visit = set([])
result = 0
def dfs(x,y,cnt):
    global result
    visit.add(graph[x][y])
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if graph[nx][ny] not in visit:
                result = max(result,cnt+1)
                dfs(nx,ny,cnt+1)
                visit.remove(graph[nx][ny])
dfs(0,0,0)
print(result+1)