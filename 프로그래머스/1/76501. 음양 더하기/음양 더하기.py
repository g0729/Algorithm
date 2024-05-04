def solution(absolutes, signs):
    return sum( a if b else -a for a,b in zip(absolutes,signs))