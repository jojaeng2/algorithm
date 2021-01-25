t = int(input())
alpha = [["A",0],["B",0],["C",0],["D",0],["E",0],["F",0],["G",0],["H",0],["I",0],["J",0]
        ,["K",0],["L",0],["M",0],["N",0],["O",0],["P",0],["Q",0],["R",0],["S",0],["T",0]
        ,["U",0],["V",0],["W",0],["X",0],["Y",0],["Z",0]]
for i in range(t):
    li = list(map(str,input()))
    for j in range(len(li)):
        for p in range(26):
            if li[j] == alpha[p][0]:
                alpha[p][1] += 10**(len(li)-j-1)
result = []
for i in range(26):
    if alpha[i][1] != 0:
        result.append(alpha[i][1])
result.sort(reverse=True)
num = 9
sum = 0
for i in result:
    sum += i*num
    num -= 1
print(sum)
