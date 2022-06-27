n,m,k = map(int,input().split())
li = [[0 for i in range(101)]for j in range(101)]
for i in range(3):
    a,b,c = map(int,input().split())
    li[i+1][1],li[i+1][2],li[i+1][3] = a,b,c
time = 0
low,column = 3,3


while li[n][m] != k and time < 100:
    time += 1
    if low >= column:
        num = 2
        for i in range(1,low+1):
            dic = {}
            for j in range(1,column+1):
                if li[i][j] != 0 and li[i][j] not in dic:
                    dic[li[i][j]] = 1
                elif li[i][j] in dic:
                    dic[li[i][j]] += 1
            log = []
            for j in range(1,column+1):
                if li[i][j] in dic:
                    log.append([li[i][j],dic[li[i][j]]])
                    del dic[li[i][j]]
            log.sort(key=lambda x:(x[1],x[0]))
            length = len(log)
            num = max(num,length*2)
            start = 1
            for j in range(length):
                li[i][start] = log[j][0] 
                li[i][start+1] = log[j][1]
                start += 2
            for j in range(start,101):
                li[i][j] = 0
        column = num
    else:
        num = 2
        for i in range(1,column+1):
            dic = {}
            for j in range(1,low+1):
                if li[j][i] != 0 and li[j][i] not in dic:
                    dic[li[j][i]] = 1
                elif li[j][i] in dic:
                    dic[li[j][i]] += 1
            log = []
            for j in range(1,low+1):
                if li[j][i] in dic:
                    log.append([li[j][i],dic[li[j][i]]])
                    del dic[li[j][i]]
            length = len(log)
            num = max(num,length*2)
            start = 1
            log.sort(key=lambda x:(x[1],x[0]))
            for j in range(length):
                li[start][i] = log[j][0] 
                li[start+1][i] = log[j][1]
                start += 2
            for j in range(start,101):
                li[j][i] = 0
        low = num
if li[n][m] == k:
    print(time)
else:
    print(-1)