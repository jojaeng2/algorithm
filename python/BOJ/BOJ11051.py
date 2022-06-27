t = int(input())
for i in range(t):
    n = int(input())
    num = list(map(int,input().split()))
    mx = num[-1]
    sum = 0
    for j in range(n-2,-1,-1):
        if num[j] >= mx:
            mx = num[j]
        else:
            sum += (mx-num[j])
    print(sum)
