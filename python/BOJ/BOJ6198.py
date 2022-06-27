import sys
input = sys.stdin.readline
n = int(input())
building = [0 for i in range(n+1)]
height = [0]
for i in range(n):
    height.append(int(input()))
stack = [n]
for i in range(n-1,0,-1):
    while stack:
        if height[i] > height[stack[-1]]:
            a = stack.pop()
            building[i] += building[a] + 1
        else:
            break
    stack.append(i)
print(sum(building))