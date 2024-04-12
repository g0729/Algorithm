def solution(arr, k):
    if k%2:
        return list(map(lambda x: x*k,arr))
    else:
        return list(map(lambda x: x+k, arr))