def solution(prices):
    answer = []
    prices.reverse()
    while len(prices) > 0:
        sum = 0
        for i in range(len(prices)-1,-1,-1):
            if prices[-1] <= prices[i]:
                sum += 1
            else:
                break
        if sum == len(prices):
            answer.append(sum-1)
        else:
            answer.append(sum)
        prices.pop()
    return answer
