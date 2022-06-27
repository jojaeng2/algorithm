from collections import deque
def solution(n, edge):
    answer = 0
    li = [[]for i in range(n+1)]
    for i in edge:
        li[i[0]].append(i[1])
        li[i[1]].append(i[0])
    visit = [0 for i in range(n+1)]
    dq = deque([1])
    visit[1] = 1
    print(li)
    while dq:
        a = dq.popleft()
        for j in li[a]:
            if visit[j] == 0:
                visit[j] = visit[a] + 1
                dq.append(j)
    result = max(visit)
    answer = visit.count(result)
    return answer
print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))