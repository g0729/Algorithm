def solution(array, n):
    return sorted([[abs(a-n),a] for a in array])[0][1]