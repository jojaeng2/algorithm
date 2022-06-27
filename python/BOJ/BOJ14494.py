n,m = map(int,input().split())
dp = [[0 for i in range(m+1)]for j in range(n+1)]
dp[1][1] = 1
for i in range(1,n+1):
    for j in range(1,m+1):
        if i == 1  and j == 1:
            pass
        else:
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1])% 1000000007
print(dp[n][m])