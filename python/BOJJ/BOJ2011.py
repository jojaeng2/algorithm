num = list(map(str,input()))
result = [0]*(len(num)+1)
result[0] = 1
result[1] = 1
if num[0] == "0":
    print(0)
else:
    for i in range(2,len(num)+1):
        if int(num[i-1]) != 0:
            result[i] = result[i-1]
        if int(num[i-2]+num[i-1]) >= 10 and int(num[i-2]+num[i-1]) <= 26:
            result[i] += result[i-2]
    print(result[len(num)]%1000000)
