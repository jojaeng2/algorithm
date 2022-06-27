def solution(board, moves):
    answer = 0
    stack = []
    for i in moves:
        for j in board:
            if j[i-1] == 0:
                pass
            else:
                stack.append(j[i-1])
                j[i-1] = 0
                break
        if len(stack) >= 2:
            if stack[-1] == stack[-2]:
                stack.pop()
                stack.pop()
                answer += 2
    return answer
