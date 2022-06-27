n = int(input())
num = list(map(int,input().split()))
up = [1 for i in range(n)]
down = [1 for i in range(n)]
for i in range(1,n):
    if num[i] == num[i-1]:
        up[i] = up[i-1] + 1
        down[i] = down[i-1] + 1
    elif num[i] > num[i-1]:
        up[i] = up[i-1] + 1
    else:
        down[i] = down[i-1] + 1
print(max(max(down),max(up)))
