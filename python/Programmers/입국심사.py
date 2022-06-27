def solution(n, times):
    answer = 0
    start,end = 1,1000000000
    while start <= end:
        mid = (start + end)//2
        num = 0
        for i in times:
            num += mid // i
            if num >= n:
                end = mid - 1
                break
        if num < n:
            start = mid + 1
    answer = mid
    return answer