def solution(numbers):
    answer = []
    n = len(numbers)
    for i in range(n-1):
        for j in range(i+1,n):
            answer.append(numbers[i]+numbers[j])
            print(i,j)
    answer = set(answer)
    answer = list(answer)
    answer.sort()
    return answer
