n = int(input())
num = list(map(int,input().split()))
sum = sum(num)
result = 0
for i in range(n):
    result += (sum-num[i])*num[i]
print(result//2)