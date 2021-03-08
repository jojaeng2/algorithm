import heapq
import sys
input = sys.stdin.readline
n = int(input())
dat = []
for i in range(n):
    dat.append(list(map(int,input().split())))

end, gas = map(int,input().split())
dat.sort(key=lambda x:(x[0],x[1]))
dat.append([end,0])
heap = []
result = 0
for i in range(n+1):
    if gas >= dat[i][0]:
        heapq.heappush(heap,(-dat[i][1],dat[i][1]))
    else:
        while gas < dat[i][0] and len(heap) > 0:
            a = heapq.heappop(heap)[1]
            gas += a
            result += 1
        if gas >= dat[i][0]:
            heapq.heappush(heap,(-dat[i][1],dat[i][1]))
        else:
            result = -1
print(result)