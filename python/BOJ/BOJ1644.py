import sys
input = sys.stdin.readline
n = int(input())
result = []
data = [True] * (n+1)
for i in range(2,int(n**0.5)+1):
    if data[i] == True:
        for j in range(i+i,n+1,i):
            data[j] = False
for i in range(2,n+1):
    if data[i] == True:
        result.append(i)
       
count,sum,right = 0,0,0
for i in range(len(result)):
    while sum < n and right < len(result):
        sum += result[right]
        right += 1
    if sum == n:
        count += 1
    sum -= result[i]
print(count)
