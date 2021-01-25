from collections import deque
n = int(input())
for i in range(n):
    stack = []
    data = deque([])
    li=list(str(input()))
    for k in range(len(li)):
        if li[k] == ">":
            if len(data) > 0:
                stack.append(data[0])
                data.popleft()
        elif li[k] == "-":
            if len(stack) > 0:
                stack.pop()
        elif li[k] == "<":
            if len(stack) >0:
                data.appendleft(stack[-1])
                stack.pop()
        else:
            stack.append(li[k])
    for p in range(len(data)):
        stack.append(data[p])
    print(''.join(stack))
