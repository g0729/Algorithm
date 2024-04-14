def solution(arr, query):
    for idx,a in enumerate(query):
        if idx%2:
            arr=arr[a:]
        else:
            arr=arr[:a+1]

            
    return arr