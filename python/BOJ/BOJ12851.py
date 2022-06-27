from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
visit = [[0,0]for i in range(100001)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
dq = deque([n])
visit[n][0],visit[n][1] = 1,1
while dq:
    a = dq.popleft()
    if 0 <= a-1 < 100001:
        if visit[a-1][0] == 0:
            visit[a-1][0] = visit[a][0] + 1
            visit[a-1][1] += 1
            dq.append(a-1)
        elif visit[a-1][0] == visit[a][0] + 1:
            visit[a-1][1] += 1
            dq.append(a-1)
    if 0 <= a+1 < 100001:
        if visit[a+1][0] == 0:
            visit[a+1][0] = visit[a][0] + 1
            visit[a+1][1] += 1
            dq.append(a+1)
        elif visit[a+1][0] == visit[a][0] + 1:
            visit[a+1][1] += 1
            dq.append(a+1)
    if 0 <= 2*a < 100001:
        if visit[2*a][0] == 0:
            visit[2*a][0] = visit[a][0] + 1
            visit[2*a][1] += 1
            dq.append(2*a)
        elif visit[2*a][0] == visit[a][0] + 1:
            visit[2*a][1] += 1
            dq.append(2*a)
print(visit[m][0]-1)
print(visit[m][1])