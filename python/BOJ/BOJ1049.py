n,m = map(int,input().split())
ans,res = 1000,1000
for i in range(m):
    a,b = map(int,input().split())
    ans = min(ans,a)
    res = min(res,b)
six = n//6
one = n % 6
if res*6 <= ans:
    print(res*6*six + res*one)
else:
    if res*one >= ans:
        print(ans*(six+1))
    else:
        print(ans*six+one*res)