def solution(route):
    answer = 1
    route.sort(key=lambda x:(x[1],x[0]))
    num = route[0][1]
    for i in range(1,len(route)):
        if route[i][0] <= num:
            pass
        else:
            num = route[i][1]
            answer += 1
    print(route)        
    return answer
print(solution([[-20,15], [-14,-5], [-18,-13], [-5,-3]]))
