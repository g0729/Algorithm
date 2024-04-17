from math import prod
def solution(box, n):
    return prod(map(lambda x : x//n,box))