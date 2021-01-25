m,n = map(int,input().split())
num = list(map(int,input()))
stack = []
num.reverse()
stack.append(num.pop())
a = n
for i in range(m-1):
    while n > 0 and stack:
        if stack[-1] < num[-1]:
            stack.pop()
            n -= 1
        else:
            break
    stack.append(num.pop())
for i in range(m-a):
    print(stack[i],end="")
