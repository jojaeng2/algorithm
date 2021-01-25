n = int(input())
li = [1,2,3,5]
for i in range(4,n):
    li.append(li[i-1]+li[i-2])
print(li[n-1]%10007)
