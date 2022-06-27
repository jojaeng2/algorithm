t = int(input())
for i in range(t):
    n = int(input())
    num = list(map(int,input().split()))
    a = []
    b = []
    num.sort()
    for j in range(n):
        if (j+1)%2 == 0:
            b.append(j)
        else:
            a.append(j)
    b.reverse()
    li = a + b
    sum = 0
    for p in range(n-1):
        sum = max(sum,abs(num[li[p]]-num[li[p+1]]))
    print(max(sum,num[1]-num[0]))
    