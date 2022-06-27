from collections import deque
def solution(length, weight, weights):
    answer = length
    bridge = deque([0]*length)
    weights = deque(weights)
    a = weights[0]
    while weights:
        print(bridge)
        print(weights)
        print(a)
        answer += 1
        a -= bridge.popleft()
        if a <= weight:
            bridge.append(weights.popleft())
            if len(weights) >= 1:
                a += weights[0]
            else:
                break
        else:
            bridge.append(0)
    return answer
print(solution(2,10,[7,4,5,6]))
