d,k = map(int,input().split())
li = [0 for i in range(d)]
li[0],li[1] = 'a','b'
for i in range(2,d):
    li[i] = li[i-1]+li[i-2]
a = li[-1].count('a')
b = li[-1].count('b')
num = 1
while True:
    if (k - num*a)%b == 0:
        b = (k - num*a)//b
        a = num
        break
    else:
        num += 1
print(a)
print(b)