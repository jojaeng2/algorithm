def solution(m, n, puddles):
    answer = 0
    path = []
    for i in range(n):
        path.append([1]*(m))
    path[0][0] = 1
    for i in range(n):
        for j in range(m):
            if i == 0:
                if [j+1,1] in puddles:
                    for p in range(j,m):
                        path[0][p] = 0
            elif j == 0:
                if [1,i+1] in puddles:
                    for p in range(i,n):
                        path[p][0] = 0
            else:
                if [j+1,i+1] in puddles:
                    path[i][j] = 0
                else:
                    path[i][j] = (path[i-1][j] + path[i][j-1]) % 1000000007
    answer = path[n-1][m-1]
    return answer
print(solution(4,3,[[2,2]]))
