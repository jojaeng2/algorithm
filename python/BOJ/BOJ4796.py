case = 1
while True:
    l,p,v = map(int,input().split())
    if l == 0 and p == 0 and v == 0:
        break
    if v%p < l:
        print("Case %s: %d" %(case, v//p*l+v%p))
    else:
        print("Case %s: %d" %(case, v//p*l+l))
    case += 1
