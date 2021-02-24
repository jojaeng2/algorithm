n = int(input())
num = list(map(int,input().split()))
result = [-1]
stack = [num[-1]]
for i in range(n-2,-1,-1):
    while True:
        if len(stack) == 0:
            stack.append(num[i])
            result.append(-1)
            break
        else:
            if num[i] < stack[-1]:
                result.append(stack[-1])
                stack.append(num[i])
                break
            else:
                stack.pop()
print(result)
print(stack)