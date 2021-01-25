n,m = map(int,input().split())
li = list(map(int,input().split()))
ten = []
nt = []
for i in li:
    if i % 10 == 0:
        ten.append(i)
    else:
        nt.append(i)
ten.sort()
sum = 0
for i in ten:
    if m == 0:
        break
    if i == 10:
        sum += 1
    else:
        if (m+1) < i//10:
            sum += m
            m = 0
        else:
            sum += i//10
            m -= (i//10)-1
for i in nt:
    if m == 0:
        break
    if m*10 < i:
        sum += m
        m = 0
    else:
        sum += i//10
        m -= i//10
print(sum)
