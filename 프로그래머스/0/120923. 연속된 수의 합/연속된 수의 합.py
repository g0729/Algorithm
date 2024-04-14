def solution(num, total):
    n=(total-((num-1)*num//2))//num
    return list(range(n,n+num))