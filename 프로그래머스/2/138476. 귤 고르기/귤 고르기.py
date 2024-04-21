from collections import defaultdict
def solution(k, tangerine):
    ma=defaultdict(int)
    for a in tangerine:
        ma[a]+=1
    arr=[]
    for key,value in ma.items():
        arr.append(value)
    arr.sort(reverse=True)
    res=0
    for a in arr:
        k-=a
        res+=1
        if k<=0:
            break
    return res
        