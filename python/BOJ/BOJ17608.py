n = int(input())
num = []
for i in range(n):
    num.append(int(input()))
result = 1
k = num[-1]
for i in range(n-2,-1,-1):
    if num[i] > k:
        k = num[i]
        result += 1
print(result)