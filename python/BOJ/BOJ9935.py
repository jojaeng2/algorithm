li = list(map(str, input()))
dq = list(map(str, input()))
stack = []
h = len(dq)
for i in range(len(li)):
    stack.append(li[i])
    if len(stack) >= h and stack[-1] == dq[-1]:
        result = True
        for p in range(-1,-h-1,-1):
            if dq[p] == stack[p]:
                pass
            else:
                result = False
                break
        if result == True:
            for j in range(h):
                stack.pop()
if len(stack) == 0:
    print('FRULA')
else:
    for i in stack:
        print(i,end="")                
