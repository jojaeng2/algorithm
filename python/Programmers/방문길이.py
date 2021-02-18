def solution(dirs):
    answer = 0
    visit = [[[0 for i in range(4)] for j in range(11)] for p in range(11)]    
    x,y = 5,5
    for i in dirs:
        if i == "U":
            if x-1 >= 0:
                if visit[x-1][y][0] == 0:
                    answer += 1
                    visit[x-1][y][0] = 1
                    visit[x][y][1] = 1
                x -= 1
        elif i == "D":
            if x+1 <11:
                if visit[x+1][y][1] == 0:
                    answer += 1
                    visit[x+1][y][1] = 1
                    visit[x][y][0] = 1
                x += 1
        elif i == "L":
            if y-1 >= 0:
                if visit[x][y-1][2] == 0:
                    answer += 1
                    visit[x][y-1][2] = 1
                    visit[x][y][3] = 1
                y -= 1
        else:
            if y+1 < 11:
                if visit[x][y+1][3] == 0:
                    answer += 1
                    visit[x][y+1][3] = 1
                    visit[x][y][2] = 1
                y += 1
    return answer
print(solution("UDU"))