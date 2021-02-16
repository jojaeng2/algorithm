n = int(input())
log = set([])
for i in range(n):
    a,b = map(str,input().split())
    if b == "enter":
        log.add(a)
    else:
        log.remove(a)
log = list(log)
log.sort(reverse=True)
for i in log:
    print(i)