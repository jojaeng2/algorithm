from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
visit = [0 for i in range(100001)]
dq = deque([n])
visit[n] = 1
dic = {n:n}
while dq:
    location = dq.popleft()
    if location == m:
        break
    if 2*location < 100001 and visit[2*location] == 0:
        visit[2*location] = 1
        dic[2*location] = location
        dq.append(2*location)
    if location-1 >= 0 and visit[location-1] == 0:
        dic[location-1] = location
        visit[location-1] = 1
        dq.append(location-1)
    if location+1 < 100001 and visit[location+1] == 0:
        dic[location+1] = location
        visit[location+1] = 1
        dq.append(location+1)

li = deque([m])
while m != dic[m]:
    li.appendleft(dic[m])
    m = dic[m]
print(len(li)-1)
for i in li:
    print(i,end=' ')