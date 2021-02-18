def solution(answers):
    answer = []
    one = [1,2,3,4,5]*2000
    two = [2,1,2,3,2,4,2,5]*1250
    three = [3,3,1,1,2,2,4,4,5,5]*1000
    x,y,z = 0,0,0
    for i in range(len(answers)):
        num = answers[i]
        if one[i] == num:
            x += 1
        if two[i] == num:
            y += 1
        if three[i] == num:
            z += 1
    num = [x,y,z]
    for i in range(3):
        if max(num) == num[i]:
            answer.append(i+1)
    return answer