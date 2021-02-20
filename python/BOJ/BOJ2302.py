dp = [1]*41
dp[2] = 2
for i in range(3,41):
    dp[i] = dp[i-1]+dp[i-2]
n = int(input())
m = int(input())
num = []
if m == 0:
    sum = dp[n]
else:
    for i in range(m):
        num.append(int(input()))
    result = [dp[num[0]-1]]*m
    for i in range(1,m):
        result[i] = dp[num[i]-num[i-1]-1]
    result.append(dp[n-num[-1]])
    sum = 1
    for i in result:
        sum *= i
print(sum)
