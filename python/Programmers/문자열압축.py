def solution(s):
    answer = len(s)
    for i in range(1, int(len(s)/2)+1):
        result = ""
        cnt = 1
        for j in range(0, len(s), i):
            if s[j : (j+i)] == s[(j+i) : (j+2*i)]:
                cnt += 1
                if j+2*i >= len(s):
                    result += str(cnt)
                    result += s[(j+i):(j+2*i)]
                    break
            else:
                if cnt == 1:
                    result += s[j : (j+i)]
                elif i+j < len(s):
                    result += str(cnt) + s[j : (j+i)]
                    cnt = 1
        answer = min(answer, len(result))
                
    return answer