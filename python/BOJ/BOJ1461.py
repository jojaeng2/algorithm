from collections import deque
n,m = map(int,input().split())
li = list(map(int,input().split()))
li.sort()
li = deque(li)
result = 0
if abs(li[0]) < abs(li[-1]):
    dat = abs(li[-1])
    if li[0] < 0:
        while li[0] < 0:
            result += abs(li[0])*2
            for i in range(m):
                if li[0] < 0:
                    li.popleft()
    while li:
        result += abs(li[-1])*2
        for i in range(m):
            if len(li) == 0:
                break
            else:
                li.pop()
    result -= dat
else:
    dat = abs(li[0])
    if li[-1] > 0:
        while li[-1] > 0:
            result += abs(li[-1])*2
            for i in range(m):
                if li[-1] > 0:
                    li.pop()
    while li:
        result += abs(li[0])*2
        for i in range(m):
            if len(li) == 0:
                break
            else:
                li.popleft()
    result -= dat
print(result)