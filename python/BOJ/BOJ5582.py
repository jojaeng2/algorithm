a =[0]+ list(map(str,input()))
b =[0]+ list(map(str,input()))
anum = len(a)
bnum = len(b)

dat = [[0 for i in range(anum)] for j in range(bnum)]

result = 0
for i in range(1,bnum):
    for j in range(1,anum):
        if a[j] == b[i]:
            dat[i][j] = dat[i-1][j-1] + 1
            result = max(result,dat[i][j])
print(result)
