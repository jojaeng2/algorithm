from collections import deque
import sys
input = sys.stdin.readline
n = int(input())
dq = deque([])
for i in range(n):
    data = list(input().split())
    if data[0] == "push":
        dq.append(int(data[1]))
    elif data[0] == "front":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[0])
    elif data[0] == "back":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq[-1])
    elif data[0] == "pop":
        if len(dq) == 0:
            print(-1)
        else:
            print(dq.popleft())
    elif data[0] == "size":
        print(len(dq))
    elif data[0] == "empty":
        if len(dq) == 0:
            print(1)
        else:
            print(0)
