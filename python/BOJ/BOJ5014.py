from collections import deque
import sys
input = sys.stdin.readline
f,s,g,u,d = map(int,input().split())
visit = [0 for i in range(f+1)]
move = [u,-d]
dq = deque([s])
visit[s] = 1
while dq:
    x = dq.popleft()
    for i in range(2):
        nx = x + move[i]
        if 1 <= nx < f+1 and visit[nx] == 0:
            dq.append(nx)
            visit[nx] = visit[x] + 1
if visit[g] == 0:
    print("use the stairs")
else:
    print(visit[g]-1)