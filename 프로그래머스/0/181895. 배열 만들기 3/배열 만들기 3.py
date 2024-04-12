def solution(arr, intervals):
    answer=[]
    for a,b in intervals:
        answer.extend(arr[a:b+1])
    return answer