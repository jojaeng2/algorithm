t = int(input())
cnt = 0
for i in range(t):
    s = list(map(str,input()))
    stack = []
    for j in s:
        if len(stack) != 0 and stack[-1] == j:
            stack.pop()
        else:
            stack.append(j)
    if stack == []:
        cnt += 1
print(cnt)
        