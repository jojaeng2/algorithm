n = int(input())
li = []
dat = []
for i in range(n):
    li.append(str(input()))
    dat.append(li[i])
dat.sort()
if dat == li:
    print('INCREASING')
else:
    dat.reverse()
    if dat == li:
        print('DECREASING')
    else:
        print('NEITHER')