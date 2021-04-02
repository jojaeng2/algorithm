import heapq
import sys
input = sys.stdin.readline
n = int(input())
li = []
for i in range(n):
    li.append(list(map(int,input().split())))

li.sort(key=lambda x:(x[1],x[2]))
heap = [li[0][2]]
cnt = 1
for i in range(1,n):
    a = heapq.heappop(heap)
    if a <= li[i][1]:
        heapq.heappush(heap,li[i][2])
    else:
        cnt += 1
        heapq.heappush(heap,li[i][2])
        heapq.heappush(heap,a)
print(cnt)