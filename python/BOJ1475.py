n = list(map(int,input()))
li = [0]*10
for i in range(len(n)):
    if n[i] == 6 or n[i] == 9:
        li[6] += 1
    else:
        li[n[i]] += 1
if li[6] % 2 == 0:
    li[6] //= 2
else:
    li[6] = li[6] // 2 + 1
print(max(li))
