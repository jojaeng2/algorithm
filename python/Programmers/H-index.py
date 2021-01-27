def solution(citations):
    answer = 0
    n = len(citations)
    data = max(citations)
    for i in range(data,-1,-1):
        sum = 0
        for j in range(n):
            if i <= citations[j]:
                sum += 1
        if sum >= i:
            answer = i
            break
    return answer
print(solution([0,1,1]))
