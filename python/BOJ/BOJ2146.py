from collections import deque
import sys
input = sys.stdin.readline
n = int(input())
graph = []
for i in range(n):
    graph.append(list(map(int,input().split())))
dx = [-1,1,0,0]
dy = [0,0,-1,1]
num = 2
visited = [[0 for i in range(n)] for j in range(n)]
q = deque([])
for i in range(n):
    for j in range(n):
        if graph[i][j] == 1 and visited[i][j] == 0:
            visited[i][j] = 1
            graph[i][j] = num
            q.append([i,j])
            while q:
                a = q.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < n and 0 <= ny < n:
                        if graph[nx][ny] == 1 and visited[nx][ny] == 0:
                            graph[nx][ny] = graph[x][y]
                            visited[nx][ny] = 1
                            q.append([nx,ny])
            num += 1

def bfs(graph,result,visit,dq,log):
    while dq:
        a = dq.popleft()
        x,y = a[0],a[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if graph[nx][ny] == 0 and visit[nx][ny] == 0:
                    visit[nx][ny] = visit[x][y] + 1
                    dq.append([nx,ny])
                elif graph[nx][ny] != log and graph[nx][ny] != 0:
                    result = min(result,visit[x][y])
                    while dq:
                        dq.pop()
                    break                
    return result
def start_log(graph,x,y):
    bl = False
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < n:
            if graph[nx][ny] != 0:
                bl = True
                break
    if bl == True:
        return graph[nx][ny]
    else:
        return 0

result = 200
for i in range(n):
    for j in range(n):
        if graph[i][j] == 0:
            log = start_log(graph,i,j)
            if log != 0:
                visit = [[0 for p in range(n)]for q in range(n)]
                visit[i][j] = 1
                dq = deque([[i,j]])
                result = min(bfs(graph,result,visit,dq,log),result)
                
print(result)