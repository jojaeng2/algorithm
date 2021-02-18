import sys
input = sys.stdin.readline
li = list(map(str,input().rstrip()))
stack = []
n = int(input())
for i in range(n):
    data = list(map(str,input().split()))
    if data[0] == "L":
        if len(li) > 0:
            stack.append(li.pop())
    elif data[0] == "D":
        if len(stack) > 0:
            li.append(stack.pop())
    elif data[0] == "P":
        li.append(data[1])
    else:
        if len(li) > 0:
            li.pop()
stack.reverse()
print(''.join(li+stack))