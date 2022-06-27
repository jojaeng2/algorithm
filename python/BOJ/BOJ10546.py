n = int(input())
dic = set([])
for i in range(2*n-1):
    st = str(input())
    if st in dic:
        dic.remove(st)
    else:
        dic.add(st)
dic = list(dic)
print(dic[0])