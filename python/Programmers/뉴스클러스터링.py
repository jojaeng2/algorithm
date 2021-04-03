dic1 = {}
dic2 = {}
minus = []
plus = []
def find(str3,dic):
    for i in range(1,len(str3)):
        if str3[i].isalpha() == True and str3[i-1].isalpha() == True:
            alpha = (str3[i-1]+str3[i]).lower()
            minus.append(alpha)
            plus.append(alpha)
            if alpha in dic:
                dic[alpha] += 1
            else:
                dic[alpha] = 1
def solution(str1, str2):
    find(str1,dic1)
    find(str2,dic2)
    minus = set(minus)
    plus = set(plus)
    minus = list(minus)
    plus = list(plus)
    
    
    answer = len(minus)
    return answer