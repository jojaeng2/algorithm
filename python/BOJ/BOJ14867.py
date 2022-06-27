from collections import deque
import sys
input = sys.stdin.readline

a,b,c,d = map(int,input().split())
dq = deque([[0,0,0]])
visit = set([(0,0)])
flag = False
while dq:
    k = dq.popleft()
    x,y,time = k[0],k[1],k[2]
    if x == c and y == d:
        flag = True
        print(time)
        break
    if (x,0) not in visit:
        dq.append([x,0,time+1])
        visit.add((x,0))
    if (0,y) not in visit:
        dq.append([0,y,time+1])
        visit.add((0,y))
    if (a,y) not in visit:
        dq.append([a,y,time+1])
        visit.add((a,y))
    if (x,b) not in visit:
        dq.append([x,b,time+1])
        visit.add((x,b))
    if x + y <= b and (0,x+y) not in visit:
        dq.append([0,x+y,time+1])
        visit.add((0,x+y))
    if x+y > b and (x+y-b,b) not in visit:
        dq.append([x+y-b,b,time+1])
        visit.add((x+y-b,b))
    if x+y <= a and (x+y,0) not in visit:
        dq.append([x+y,0,time+1])
        visit.add((x+y,0))
    if x+y>a and (a,x+y-a) not in visit:
        dq.append([a,x+y-a,time+1])
        visit.add((a,y+x))
if flag == False:
    print(-1)