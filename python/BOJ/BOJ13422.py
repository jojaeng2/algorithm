import sys
input = sys.stdin.readline
t = int(input())
for i in range(t):
    n,m,k = map(int,input().split())
    li = list(map(int,input().split()))
    start,end,sum = 0,m-1,0
    for i in range(m):
        sum += li[i]
    count = 0
    if m == n:
        if sum < k:
            count += 1
        print(count)
    else:
        while start < n:
            end += 1
            if end == n:
                end = 0
            sum += (li[end] - li[start])
            start += 1
            if sum < k:
                count += 1
        print(count)
