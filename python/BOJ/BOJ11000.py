import heapq
import sys
input = sys.stdin.readline

n = int(input())
result = 1
num = []
for i in range(n):
    num.append(list(map(int,input().split())))
num.sort(key=lambda x:(x[0]))
hp = [(num[0][1],num[0][0])]
for i in range(1,n):
    print(hp)
    if num[i][0] >= hp[0][0]:
        heapq.heappop(hp)
    else:
        result += 1
    heapq.heappush(hp,(num[i][1],num[i][0]))
    
print(result)