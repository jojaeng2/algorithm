w,h = map(int,input().split())
a,b = map(int,input().split())
dp = [[0 for i in range(w+1)] for j in range(h+1)]
for i in range(1,b+1):
    for j in range(1,a+1):
        if i == 1 and j == 1:
            dp[1][1] = 1
        else:
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000007
for i in range(b,h+1):
    for j in range(a,w+1):
        if i == 1 and j == 1:
            dp[1][1] = 1
        else:
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000007
print(dp[h][w])