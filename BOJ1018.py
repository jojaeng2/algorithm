N,M = map(int,input().split())
li = []
for i in range(N):
    li.append(list(input()))
data = []
for p in range(N-7):
    for q in range(M-7):
        result1 = 0
        result2 = 0
        for i in range(p,p+8):
            for k in range(q,q+8):
                if (i+k)%2 == 0:
                    if li[i][k] != "B":
                        result1 += 1
                    if li[i][k] != "W":
                        result2 += 1
                else:
                    if li[i][k] != "W":
                        result1 += 1
                    if li[i][k] != "B":
                        result2 += 1

        data.append(result1)
        data.append(result2)
print(min(data))
