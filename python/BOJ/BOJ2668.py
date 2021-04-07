dat = [1 for i in range(10)]
now = 10
num = [0,10]
li = [0 for i in range(10)]
for i in range(2,65):
    li[0] = now
    for j in range(1,10):
        li[j] = now - dat[j-1]
        now -= dat[j-1]
    now = sum(li)
    num.append(now)
    for j in range(10):
        dat[j] = li[j]

t = int(input())
for i in range(t):
    n = int(input())
    print(num[n])