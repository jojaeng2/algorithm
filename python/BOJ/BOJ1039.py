import sys
from collections import deque
input = sys.stdin.readline
n,k = map(int,input().split())
dq = deque([[n,0]])
visit = set((n,0))
result = 0
while dq:
    a = dq.popleft()
    x,cnt = a[0],a[1]
    if cnt == k:
        result = max(x,result)
    print(x,cnt)
    if cnt < k:
        li = []
        div = 1000000
        while div != 0:
            if x // div != 0:
                li.append(x//div)
                x %= div
            elif len(li) > 0 and x // div == 0:
                li.append(0)
            div //= 10
        for i in range(len(li)):
            for j in range(len(li)):
                if i == j:
                    pass
                elif i == 0 and li[j] == 0:
                    pass
                elif j == 0 and li[i] == 0:
                    pass
                else:
                    dat = li[j]
                    li[j] = li[i]
                    li[i] = dat
                    num = ''
                    for p in range(len(li)):
                        num += str(li[p])
                    num = int(num)
                    if (num,cnt+1) not in visit:
                        visit.add((num,cnt+1))
                        dq.append([num,cnt+1])
                    dat = li[j]
                    li[j] = li[i]
                    li[i] = dat
if cnt < k:
    print(-1)
else:
    print(result)