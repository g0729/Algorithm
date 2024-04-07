def solution(price, money, count):
    return max(0,((count*(count+1)//2)*price)-money)