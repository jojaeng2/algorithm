li = list(map(str,input()))
dq = list(map(str,input()))
result = []
for i in range(len(dq)+1):
    result.append([0]*len(li))
for i in range(len(dq)):
    for j in range(len(li)):
        if j == 0:
            if dq[i] == li[j]:
                result[i][j] = 1
            else:
                result[i][j] = result[i-1][j]
        else:
            if dq[i] == li[j]:
                result[i][j] = result[i-1][j-1] + 1
            else:
                result[i][j] = max(result[i-1][j], result[i][j-1])
print(max(result[-2]))
