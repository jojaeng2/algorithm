import sys
input = sys.stdin.readline
n,m = map(int,input().split())
result = []
for i in range(n):
    result.append(list(map(int,input().split())))
for p in range(n):
    for q in range(n):
        if p == 0 and q == 0:
            pass
        elif p == 0:
            result[p][q] += result[p][q-1]
        elif q ==0:
            result[p][q] += result[p-1][q]
        else:
            result[p][q] += result[p-1][q] + result[p][q-1] - result[p-1][q-1]
for i in range(m):
    x1,y1,x2,y2 = map(int,input().split())
    if x1 == 1 and y1 == 1:
        print(result[x2-1][y2-1])
    elif x1 == 1:
        print(result[x2-1][y2-1]-result[x2-1][y1-2])
    elif y1 == 1:
        print(result[x2-1][y2-1]-result[x1-2][y2-1])
    else:
        print(result[x2-1][y2-1]-result[x1-2][y2-1]-result[x2-1][y1-2]+result[x1-2][y1-2])
