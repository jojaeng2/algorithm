num = int(input())
li = [1,2,4]
for i in range(3,10):
    li.append(li[i-1]+li[i-2]+li[i-3])
print(li)
