import sys
num = [0]*1000001
input = sys.stdin.readline
num[2],num[3] = 1,1
for i in range(4,1000001):
    if i % 3 == 0 and i % 2 == 0:
        num[i] = min(num[i//3]+1,num[i//2]+1,num[i-1]+1)
    elif i % 3 == 0:
        num[i] = min(num[i//3]+1,num[i-1]+1)
    elif i % 2 == 0:
        num[i] = min(num[i//2]+1,num[i-1]+1)
    else:
        num[i] = num[i-1]+1
n = int(input())
print(num[n])    