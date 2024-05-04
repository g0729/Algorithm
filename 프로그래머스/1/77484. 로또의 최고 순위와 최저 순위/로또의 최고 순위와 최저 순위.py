def solution(lottos, win_nums):
    answer = []
    zero=lottos.count(0)
    cnt=0
    for a in lottos:
        if a in win_nums:
            cnt+=1
    return [min(7-(cnt+zero),6),min(7-cnt,6)]