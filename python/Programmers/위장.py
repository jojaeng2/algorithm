def solution(clothes):
    answer = 0
    dic = {}
    for i in clothes:
        if i[1] not in dic:
            dic[i[1]] = 2
        else:
            dic[i[1]] += 1
    dic = dic.values()
    sum = 1
    for i in dic:
        sum *= i
    answer = sum - 1
    return answer
