def solution(A, B):
    answer = 0
    A.sort()
    B.sort()
    while A:
        a = A.pop()
        if a < B[-1]:
            answer += 1
            B.pop()
    return answer