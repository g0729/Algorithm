def solution(arr, queries):
    for s,e,k in queries:
        for i in range(s,e+1):
            arr[i]= arr[i] if i%k else arr[i]+1
    return arr