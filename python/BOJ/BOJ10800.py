import sys
input = sys.stdin.readline
n = int(input())
ball = []
for i in range(n):
    a,b = map(int,input().split())
    ball.append([a,b,i])
ball.sort(key=lambda x:(x[1],x[0]))
money = [0 for i in range(n+1)]
dic = {}
snum = 0

s = [0] * (n+1)
now = ball[0][1]
csum = 0

for i in range(n):
    money[ball[i][0]] += ball[i][1]
    snum += ball[i][1]
    if now == ball[i][1]:
        csum += ball[i][1]
        s[ball[i][0]] += ball[i][1]
        dic[ball[i][2]] = snum - money[ball[i][0]] - csum + s[ball[i][0]]
    else:
        csum = ball[i][1]
        s = [0] * (n+1)
        now = ball[i][1]
        s[ball[i][0]] = ball[i][1]
        dic[ball[i][2]] = snum - money[ball[i][0]]

for i in range(n):
    print(dic[i])