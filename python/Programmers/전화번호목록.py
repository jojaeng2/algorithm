def solution(phone):
    answer = True
    phone.sort()
    print(phone)
    for i in range(len(phone)-1):
        if phone[i] == phone[i+1][:len(phone[i])]:
            answer = False
            break
    return answer
solution(["12","123","1235","567","88"])
