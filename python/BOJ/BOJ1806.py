import sys
input = sys.stdin.readline
n,m = map(int,input().split())
num = list(map(int,input().split()))
start,end,sum = 0,0,num[0]
result = n
while start <= end and end < n:
    if sum >= m:
        result = min(result,end-start)
        sum -= num[start]
        start += 1
    else:
        end += 1
        if end == n:
            break
        sum += num[end]
if result == n:
    print(0)
else:
    print(result+1)
