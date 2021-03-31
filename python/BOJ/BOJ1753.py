import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)
n,m = map(int,input().split())
start = int(input())
graph = [[]for i in range(n+1)]
visit = [INF] * (n+1)

for i in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))

def daik(start):
    hq = []
    heapq.heappush(hq,(0,start))
    visit[start] = 0
    while hq:
        distance,node = heapq.heappop(hq)
        if visit[node] < distance:
                continue
        for i in graph[node]:
            cost = distance + i[1]
            if cost < visit[i[0]]:
                visit[i[0]] = cost
                heapq.heappush(hq,(cost,i[0]))
daik(start)
for i in range(1,n+1):
    if visit[i] == INF:
        print("INF")
    else:
        print(visit[i])
print(visit)