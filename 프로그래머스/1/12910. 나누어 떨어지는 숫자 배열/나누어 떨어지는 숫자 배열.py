def solution(arr, divisor):
    answer=sorted([n for n in arr if n%divisor==0])
    if len(answer)==0:
         return [-1]
    return answer