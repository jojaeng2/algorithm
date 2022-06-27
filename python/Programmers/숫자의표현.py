def solution(n):
    answer = 1
    num = []
    for i in range(1,n+1):
        num.append(i)
    start,end = 0,1
    if n <= 2:
        print(1)
    else:
        sum = num[start] + num[end]
        while start < end and end < n:
            if sum == n:
                answer += 1
                end += 1
                sum += num[end]
            elif sum < n:
                end += 1
                sum += num[end]
            else:
                sum -= num[start]
                start += 1
    return answer
print(solution(15))
