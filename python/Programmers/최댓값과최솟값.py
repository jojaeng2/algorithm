def solution(s):
    answer = ''
    result = list(map(int,s.split()))
    result.sort()
    answer = str(result[0]) + " " + str(result[-1])
    return answer
