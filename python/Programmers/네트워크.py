def solution(n, computers):
    answer = 0
    visit = [[0 for i in range(n)]for j in range(n)]
    stack = []
    for i in range(n):
        for j in range(n):
            if computers[i][j] == 1 and visit[i][j] == 0:
                stack.append([i,j])
                answer += 1
                while stack:
                    a = stack.pop()
                    x,y = a[0],a[1]
                    visit[x][y] = 1
                    visit[y][x] = 1
                    for p in range(n):
                        if computers[x][p] == 1 and visit[x][p] == 0:
                            stack.append([x,p])
                    for p in range(n):
                        if computers[y][p] == 1 and visit[y][p] == 0:
                            stack.append([y,p])
    return answer