from collections import deque
t = int(input())
for i in range(t):
    n = int(input())
    dq = list(map(str,input().split()))
    dq = deque(dq)
    dat = deque([])
    dat.append(dq.popleft())
    for j in range(n-1):
        st = dq.popleft()
        if st <= dat[0]:
            dat.appendleft(st)
        else:
            dat.append(st)
    dat = list(dat)
    print(''.join(dat))