def solution(A, B):
    for i in range(len(A)):
        if A[-i:]+A[:-i]==B:
            return i
    return -1