import sys
input =sys.stdin.readline
while True:
    m,n = map(int,input().split())
    if m == 0 and n == 0:
        break
    li = []
    result = []
    for i in range(m):
        li = list(map(int,input().split()))
        if len(li) >= 2:
            if li[1] < li[0]:
                li[1] = li[0]
        for j in range(2,n):
            li[j] = max(li[j-1],li[j-2]+li[j])
        result.append(li[-1])
    if len(result) >= 2:
        if result[1] < result[0]:
            result[1] = result[0]
    for i in range(2,m):
        result[i] = max(result[i-2]+result[i],result[i-1])
    print(result[-1])
