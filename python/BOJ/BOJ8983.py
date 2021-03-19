import sys
input = sys.stdin.readline
m,n,k = map(int,input().split())
li = list(map(int,input().split()))
li.sort()
result = 0
for i in range(n):
    x,y = map(int,input().split())
    start,end = 0,m-1
    while start < end:
        mid = (start+end)//2
        if x > li[mid]:
            start = mid + 1
        else:
            end = mid - 1
    mid = (start+end)//2
    plus = mid + 1
    minus = mid - 1
    if plus >= m:
        plus = mid
    elif minus < 0:
        minus = 0
    if abs(li[mid]-x) + y <= k:
        result += 1
    elif abs(li[minus]-x) + y <= k:
        result += 1
    elif abs(li[plus]-x) + y <= k:
        result += 1
print(result)