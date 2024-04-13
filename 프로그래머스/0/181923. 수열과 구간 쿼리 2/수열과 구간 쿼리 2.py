def solution(arr, queries):
    answer=[]
    for a,b,k in queries:
        try:
            answer.append(min([c for c in arr[a:b+1] if c>k]))
        except:
            answer.append(-1)
    return answer