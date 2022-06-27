from collections import deque
def solution(pri,location):
    answer = 0
    pri = deque(pri)
    result = deque(([0]*len(pri)))
    result[location] = 1
    while pri:
        print(pri)
        print(result)
        if pri[0] == max(pri):
            pri.popleft()
            if result.popleft() == 1:
                answer += 1
                break
            else:
                answer += 1
        else:
            pri.append(pri.popleft())
            result.append(result.popleft())
    return answer
print(solution([1, 1, 9, 1, 1, 1],0))
