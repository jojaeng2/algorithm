import sys
import heapq
input = sys.stdin.readline
t = int(input())
result = []
for i in range(t):
    n = int(input())
    max_hq = []
    min_hq = []
    dic = {}
    for j in range(n):
        a,b = input().split()
        if a == "I":
            b = int(b)
            heapq.heappush(min_hq,(b,b))
            heapq.heappush(max_hq,(-b,b))
            if b in dic:
                dic[b] += 1
            else:
                dic[b] = 1
        else:
            if b == "-1":
                while len(min_hq) > 0:
                    pop_num = heapq.heappop(min_hq)
                    if dic[pop_num[1]] > 0:
                        dic[pop_num[1]] -= 1
                        break                    
            else:
                while len(max_hq) > 0:
                    pop_num = heapq.heappop(max_hq)
                    if dic[pop_num[1]] > 0:
                        dic[pop_num[1]] -= 1
                        break
    x,y = "EMPTY","EMPTY"
    while len(max_hq) > 0:
        pop_num = heapq.heappop(max_hq)
        if dic[pop_num[1]] > 0:
            x = pop_num[1]
            break
    while len(min_hq) > 0:
        pop_num = heapq.heappop(min_hq)
        if dic[pop_num[1]] > 0:
            y = pop_num[1]
            break
    if x != "EMPTY" and y != "EMPTY":
        print(x,y)
    else:
        print("EMPTY")