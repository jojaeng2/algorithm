def solution(skill, skill_trees):
    answer = 0
    for i in skill_trees:
        result = []
        for j in range(len(i)):
            if i[j] in skill:
                result.append(i[j])
        data = -1
        sum = True
        for i in result:
            index = skill.index(i)
            if index == data+1:
                data = index
            else:
                sum = False
                break
        if sum == True:
            answer += 1
    return answer
print(solution("CBD",["BACDE", "CBADF", "AECB", "BDA"]))
