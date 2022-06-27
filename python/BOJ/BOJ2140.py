n = int(input())
dat = []
for i in range(n):
    dat.append(list(map(str,input())))
dx = [0,0,-1,1,-1,-1,1,1]
dy = [-1,1,0,0,-1,1,-1,1]
cnt = 0
for i in range(n):
    for j in range(n):
        if dat[i][j] != "#":
            dat[i][j] = int(dat[i][j])
for i in range(n):
    for j in range(n):
        if dat[i][j] == "#":
            result = True
            for p in range(8):
                nx = i + dx[p]
                ny = j + dy[p]
                if 0 <= nx < n and 0 <= ny < n:
                    if dat[nx][ny] == 0:
                        result = False
            if result == True:
                cnt += 1
                for p in range(8):
                    nx = i + dx[p]
                    ny = j + dy[p]
                    if 0 <= nx < n and 0 <= ny < n:
                        if dat[nx][ny] != "#" and dat[nx][ny] != 0:
                            dat[nx][ny] -= 1
print(cnt)