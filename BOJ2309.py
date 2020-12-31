li = []
for i in range(9):
    li.append(int(input()))
li.sort()
sum = sum(li)
for i in range(9):
    for k in range(9):
        if sum - (li[i]+li[k]) == 100:
            num1 = li[i]
            num2 = li[k]
li.remove(num1)
li.remove(num2)    
for i in range(7):
    print(li[i])
