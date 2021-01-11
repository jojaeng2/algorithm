n = int(input())
pl = []
mi = []
for i in range(n):
    num = int(input())
    if num <= 0:
        mi.append(num)
    else:
        pl.append(num)
sum = 0
mi.sort()
for i in range(0,len(mi), 2):
    if i == len(mi)-1:
        sum += mi[i]
    else:
        sum += mi[i]*mi[i+1]
pl.sort(reverse=True)
for i in range(0,len(pl), 2):
    if i == len(pl)-1:
        sum += pl[i]
    else:
        if pl[i] == 1 or pl[i+1] == 1:
            sum += pl[i]+pl[i+1]
        else:
            sum += pl[i]*pl[i+1]
print(sum)
