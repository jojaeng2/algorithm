from collections import deque
dq = []
n = int(input())
for i in range(n):
    dq.append(int(input()))
result = 0
while len(dq) > 1:
    sum = 0
    dq = list(dq)
    dq.sort()
    dq = deque(dq)
    for i in range(2):
        sum += dq.popleft()
    dq.append(sum)
    result += sum
print(result)
