import sys
input = sys.stdin.readline
n,m = map(int,input().split())
li = {}
dat = []
for i in range(n):
    dat.append(input().rstrip())
    li[dat[-1]] = i+1
for i in range(m):
    answer = input().rstrip()
    if answer.isdigit() == True:
        print(dat[int(answer)-1])
    else:
        print(li[answer])