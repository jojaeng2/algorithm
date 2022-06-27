import sys
from collections import deque
input = sys.stdin.readline
t = int(input())
def bfs(flag):
    while dq:
        x = dq.popleft()
        for p in range(len(graph[x])):
            if visit[graph[x][p]] == 0:
                if visit[x] == 1:
                    visit[graph[x][p]] = 2
                else:
                    visit[graph[x][p]] = 1
                dq.append(graph[x][p])
            else:
                if visit[graph[x][p]] == visit[x]:
                    flag = False
                    return

for i in range(t):
    v,e = map(int,input().split())
    graph = [[]for p in range(v+1)]
    visit = [0 for p in range(v+1)]
    dq = deque([])
    for j in range(e):
        a,b = map(int,input().split())
        graph[a].append(b)
        graph[b].append(a)
    flag = True
    for j in range(1,v+1):
        if visit[j] == 0:
            visit[j] = 1
            dq.append(j)
            bfs(flag)
    if flag == False:
        print("NO")
    else:
        print("YES")
