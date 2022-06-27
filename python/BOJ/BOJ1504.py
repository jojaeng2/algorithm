import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)
n,m = map(int,input().split())
graph = [[]for i in range(n+1)]
for i in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))
v1,v2 = map(int,input().split())

def daik(start):
    visit = [INF] * (n+1)
    heap = []
    heapq.heappush(heap,(0,start))
    visit[start] = 0
    while heap:
        dist,now = heapq.heappop(heap)
        if visit[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < visit[i[0]]:
                visit[i[0]] = cost
                heapq.heappush(heap,(cost,i[0]))
    return visit

daik(1)
a = visit(v1)
b = visit[v2]

daik(v1)
c = visit[v2]
d = visit[n]

daik(v2)
e = visit[n]
f = visit[v1]

answer = min(a+c+e,b+f+d)
if answer >= INF:
    print(-1)
else:
    print(answer)