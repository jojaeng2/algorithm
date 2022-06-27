n = int(input())
init = []
out = {}
for i in range(n):
    init.append(str(input()))
for i in range(n):
    a = str(input())
    out[a] = i
result = 0
for i in range(n):
    for j in range(i-1,-1,-1):
        if out[init[i]] < out[init[j]]:
            result += 1
            print(init[i],init[i-1])
            break
print(result)