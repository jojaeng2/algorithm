def solution(new_id):
    answer = ''
    result = []
    new_id = new_id.lower()
    for i in new_id:
        if i.isalpha() == True or i.isdigit() == True or i == "-" or i == "_" or i == ".":
            result.append(i)
    data = []
    index = 0
    while index <= len(result)-1:
        if index == len(result) - 1:
            if result[-1] == ".":
                pass
            else:
                data.append(result[-1])
            break
        elif result[index] == "." and result[index+1] == ".":
            index += 1
        else:
            data.append(result[index])
            index += 1
    if len(data) > 0:
        if data[0] == ".":
            data.remove(".")
    if len(data) == 0:
        data.append("a")
    elif len(data) >= 16:
        for i in range(len(data)-15):
            data.pop()
    while True:
        if data[-1] == ".":
            data.pop()
        else:
            break
    if len(data) == 2:
        data.append(data[-1])
    elif len(data) == 1:
        a = data[-1]
        data.append(a)
        data.append(a)
    for i in data:
        answer += str(i)
    return answer
print(solution("=.="))
