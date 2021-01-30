def solution(record):
    answer = []
    result = []
    dic = {}
    for i in record:
        result.append(list(i.split()))
    for i in result:
        if i[0] == "Enter" or i[0] == "Change":
            dic[i[1]] = i[2]
    for i in result:
        if i[0] == "Enter":
            answer.append(dic[i[1]]+"님이 들어왔습니다.")
        elif i[0] == "Leave":
            answer.append(dic[i[1]]+"님이 나갔습니다.")
    return answer
