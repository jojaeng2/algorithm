n = int(input())
num = []
for i in range(n):
    num.append(list(map(int,input().split())))
num.sort(key=lambda x:(-x[0],-x[1]))
dat = [0 for i in range(10000)]
for i in range(n):
    for j in range(num[i][1]-1,-1,-1):
        if dat[j] == 0:
            dat[j] = num[i][0]
            break
print(dat)
print(sum(dat))