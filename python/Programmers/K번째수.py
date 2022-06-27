def solution(array, commands):
    answer = []
    for i in commands:
        result = []
        for j in range(i[0]-1,i[1]):
            result.append(array[j])
        answer.append(result[i[2]-1])
    print(result)

    return answer
print(solution([1,5,2,6,3,7,4],[[2,5,3],[4,4,1],[1,7,3]]))
