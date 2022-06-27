def solution(parti, completion):
    answer = ''
    parti.sort()
    completion.sort()
    for i in range(len(completion)):
        if parti[i] != completion[i]:
            answer += parti[i]
            break
    if answer == "":
        answer += parti[-1]
    return answer
