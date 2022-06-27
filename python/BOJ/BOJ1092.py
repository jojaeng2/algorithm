import sys
input = sys.stdin.readline
n = int(input())
fork = list(map(int,input().split()))
k = int(input())
box = list(map(int,input().split()))
fork.sort(reverse=True)
box.sort()
log = []
time = 0
if fork[0] < box[-1]:
    print(-1)
else:
    while box or log:
        time += 1
        dat = []
        for i in range(n):
            while len(dat) != n and len(box) != 0:
                if box[-1] > fork[i]:
                    log.append(box.pop())
                else:
                    dat.append(box.pop())
                    break
        print(dat)
        for i in range(len(log)):
            box.append(log.pop())
    print(time)