n = int(input())
li = [1]*90
for i in range(2,90):
    li[i] = li[i-1]+li[i-2]
print(li[n-1])
