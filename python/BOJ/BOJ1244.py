n = int(input())
num =[0] + list(map(int,input().split()))
m = int(input())
dat = []
for i in range(m):
    dat.append(list(map(int,input().split())))
for i in dat:
    if i[0] == 1:
        for j in range(1,n+1):
            if j % i[1] == 0:
                if num[j] == 0:
                    num[j] = 1
                else:
                    num[j] = 0
    else:
        left,right = i[1], i[1]
        while left >= 1 and right <= n:
            if num[left] == num[right]:
                if num[left] == 0:
                    num[left] = 1
                    num[right] = 1
                else:
                    num[left] = 0
                    num[right] = 0
                left -= 1
                right += 1
            else:
                break
for i in range(1,n+1,20):
    print(*num[i:i+20])