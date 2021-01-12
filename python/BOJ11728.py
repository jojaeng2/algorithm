n,m = map(int,input().split())
li = list(map(int,input().split()))
dq = list(map(int,input().split()))
li.extend(dq)
li.sort()
for i in li:
    print(i,end = " ")
