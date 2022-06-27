import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)
n = int(input())
m = int(input())
graph = [[]for i in range(n+1)]
for i in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
visit = [INF] * (n+1)
path = [i for i in range(n+1)]
start,end = map(int,input().split())
def daik(start):
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
                path[i[0]] = now
                visit[i[0]] = cost
                heapq.heappush(heap,(cost,i[0]))
daik(start)
print(visit[end])
result = []
while end != path[end]:
    result.append(end)
    end = path[end]
result.append(start)
result.reverse()
print(len(result))
print(*result)