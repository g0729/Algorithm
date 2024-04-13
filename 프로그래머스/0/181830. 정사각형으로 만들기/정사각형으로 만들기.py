def solution(arr):
    a,b=len(arr),len(arr[0])
    c=max(a,b)
    answer=[[0 for _ in range(c) ] for _ in range(c)]
    for i in range(a):
        for j in range(b):
            answer[i][j]=arr[i][j]
    return answer