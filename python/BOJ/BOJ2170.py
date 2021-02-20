import sys
input = sys.stdin.readline
n = int(input())
li = []
for i in range(n):
    li.append(list(map(int,input().split())))
li.sort(key=lambda x:(x[0],x[1]))
start,end = li[0][0],li[0][1]
sum = 0
for i in range(1,n):
    fir = li[i][0]
    sec = li[i][1]
    if fir <= end:
        if sec > end:
            end = sec
    else:
        sum += (end-start)
        start = fir
        end = sec
sum += (end-start)
print(sum)