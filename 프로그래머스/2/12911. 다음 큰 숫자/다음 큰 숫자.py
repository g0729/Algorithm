def solution(n):
    cnt=list(bin(n)).count('1')
    n+=1
    while True:
        if list(bin(n)).count('1')==cnt:
            return n
        n+=1