import sys
input = sys.stdin.readline
n,m = map(int,input().rstrip().split())
cnt = int(input())
visit = [[0 for i in range(m+1)]]
for i in range(n):
    visit.append([0]+list(map(str,input().rstrip())))
num = [[[0,0,0] for i in range(m+1)]for j in range(n+1)]
for k in range(1,n+1):
    j,o,i = 0,0,0
    for p in range(1,m+1):
        for q in range(3):
            num[k][p][q] = num[k-1][p][q]
        if visit[k][p] == "J":
            j += 1
        elif visit[k][p] == "O":
            o += 1
        elif visit[k][p] == "I":
            i += 1
        num[k][p][0] += j
        num[k][p][1] += o
        num[k][p][2] += i

for i in range(cnt):
    x1,y1,x2,y2 = map(int,input().split())
    J,O,I = 0,0,0
    J = num[x2][y2][0] - num[x2][y1-1][0] - num[x1-1][y2][0] + num[x1-1][y1-1][0]
    O = num[x2][y2][1] - num[x2][y1-1][1] - num[x1-1][y2][1] + num[x1-1][y1-1][1]
    I = num[x2][y2][2] - num[x2][y1-1][2] - num[x1-1][y2][2] + num[x1-1][y1-1][2]
    print(J,O,I)