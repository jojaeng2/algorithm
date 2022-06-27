n = int(input())
dic = {}
for i in range(n):
    num = int(input())
    if num in dic:
        dic[num] += 1
    else:
        dic[num] = 1
dic = sorted(dic.items(),key=lambda x: (-x[1],x[0]))
print(dic[0][0])