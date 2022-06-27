import sys
sys.setrecursionlimit(10000)
input = sys.stdin.readline

n, l, r = list(map(int, input().split()))
people = [list(map(int, input().split())) for _ in range(n)]
# 국경선을 열 나라를 찾기 위해 이미 찾은 좌표를 체크해두는 array - false로 초기화
check = [[False] * n for _ in range(n)]

# 인구 이동 횟수를 count
answer = 0

# 국경선을 열 나라를 dfs 방식으로 체크하는 함수
def isopen(x, y, temp, check):
    check[x][y] = True
    # 수평 또는 수직으로 인접한 좌표의 인구 차이가 l이상 r 이하라면 새로운 리스트(연합)을 만들어서 좌표 넣음
    for dx, dy in ((0, 1),(0, -1),(1, 0),(-1, 0)):
        nx, ny = x + dx, y + dy
        if nx < 0 or nx >= n or ny <0 or ny >= n:
            continue
        if not check[nx][ny] and l<=abs(people[x][y] - people[nx][ny])<=r:
            temp.append((nx, ny))
            isopen(nx, ny, temp, check)

# 더 이상 인구 이동이 없을 때까지
while True:
    migrate = False
    # 1. 특정 조건을 만족하는 나라에 대하여 국경선 열기
    check = [[False] * n for _ in range(n)]
    for idx in range(n):
        for jdx in range(n):
            # check arr에 대하여 아직 검사하지 않은 나라들에 대하여 계속 검사
            if not check[idx][jdx]:
                temp = [(idx, jdx)]
                isopen(idx, jdx, temp, check)
                if len(temp) > 1:
                    migrate = True
                    # 2. 국경선이 열려 있는 나라들의 인구를 연합의 인구수 / 연합을 이루고 있는 칸의 개수로 재설정
                    cnt = sum([people[x][y] for x, y in temp]) // len(temp)
                    for x, y in temp:
                        people[x][y] = cnt

    if migrate:
        answer += 1
    else:
        break

print(answer)