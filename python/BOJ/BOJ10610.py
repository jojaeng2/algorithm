li = list(map(int,input()))
li.sort(reverse=True)
if 0 in li and sum(li) % 3 == 0:
    print(''.join(map(str,li)))
else:
    print(-1)
