from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
dq = deque([n])
visit = [0 for i in range(100001)]
visit[n] = 1
def bfs():
    while dq:
        location = dq.popleft()
        if location == m:
            break
        if 0 <= 2 * location < 100001 and visit[2*location] == 0:
            visit[2*location] = visit[location]
            dq.append(2*location)
        if 0 <= location - 1 < 100001 and visit[location-1] == 0:
            visit[location-1] = visit[location] + 1
            dq.append(location-1)
        if 0 <= location + 1 < 100001 and visit[location+1] == 0:
            visit[location + 1] = visit[location] + 1
            dq.append(location+1)
bfs()
print(visit[m]-1)