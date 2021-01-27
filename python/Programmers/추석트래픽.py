def solution(lines):
    answer = 0
    result = []
    for i in range(len(lines)):
        result.append([0,0])
    for i in range(len(lines)):
        result[i][1] = (int(lines[i][11:13])*3600+int(lines[i][14:16])*60+int(lines[i][17:19]))*1000+int(lines[i][20:23])
        result[i][0] = result[i][1] - int(float(lines[i][24:-1])*1000) + 1
    result.sort(key = lambda x:x[0])
    a = []
    data = [0,0]
    for i in range(len(result)):
        sum = 0
        data[0] = result[i][0] - 999
        data[1] = result[i][0]
        for j in result:
            if j[0] > data[1] or j[1] < data[0]:
                pass
            else:
                sum += 1
        a.append(sum)
    answer = max(a)
    return answer
print(solution(["2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"]))
