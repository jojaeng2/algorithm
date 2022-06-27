def solution(progres, speeds):
    answer = []
    for i in range(len(progres)):
        progres[i] = 100 - progres[i]
    for i in range(len(speeds)):
        if progres[i] % speeds[i] == 0:
            progres[i] = progres[i] // speeds[i]
        else:
            progres[i] = progres[i] // speeds[i] + 1
    print(progres)
    progres.reverse()
    sum = 0
    while progres:
        print(progres)
        if progres[-1] <= 0:
            progres.pop()
            sum += 1
        else:
            end = progres[-1]
            if sum == 0:
                for i in range(len(progres)):
                    progres[i] -= end
            else:
                answer.append(sum)
                sum = 0
                for i in range(len(progres)):
                    progres[i] -= end
    answer.append(sum)
    return answer
print(solution(	[5, 5, 5], [21, 25, 20]))
