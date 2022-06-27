from collections import deque
n,m = map(int,input().split())
visit = [0 for i in range(100001)]
dq = deque([n])
visit[n] = 1
while dq:
    a = dq.popleft()
    if a == m:
        break
    if 0 <= a-1 < 100001 and visit[a-1] == 0:
        visit[a-1] = visit[a] + 1
        dq.append(a-1)
    if 0 <= a+1 < 100001 and visit[a+1] == 0:
        visit[a+1] = visit[a] + 1
        dq.append(a+1)
    if 0 <= 2*a < 100001 and visit[2*a] == 0:
        visit[2*a] = visit[a] + 1
        dq.append(2*a)
print(visit[m]-1)
