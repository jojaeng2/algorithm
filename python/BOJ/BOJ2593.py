n = int(input())
result = [0]
num = list(map(int,input().split()))
stack = [0 for i in range(n)]
for i in range(1,n):
    while True:
        if len(stack) == 0:
            stack.append(i)
            result.append(0)
            break
        if num[stack[-1]] <= num[i]:
            stack.pop()
        else:
            result.append(stack[-1]+1)
            stack.append(i)
            break
for i in result:
    print(i,end=" ")