def solution(arr):
    a=[idx for idx in range(len(arr)) if arr[idx]==2]
    return arr[a[0]:a[-1]+1]if len(a) else [-1]