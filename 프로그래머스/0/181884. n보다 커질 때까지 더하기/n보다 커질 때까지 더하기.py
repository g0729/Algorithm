def solution(numbers, n):
    sum=0
    for a in numbers:
        sum+=a
        if sum>n:
            return sum
    