num = list(map(int,input().split()))
result = []
for i in num:
    result.append(i)
result.sort()
if result == num:
    print('ascending')
else:
    result.sort(reverse=True)
    if result == num:
        print('descending')
    else:
        print('mixed')