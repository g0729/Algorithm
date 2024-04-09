def check(target,n,times):
    
    cnt=0
    for time in times:
        cnt+=target//time
        
    if cnt>=n:
        return True
    else:
        return False
    
def bin_search(n,times):
    left,right=0,int(1e17)
    
    while left+1<right:
        mid=(left+right)//2
        
        if check(mid,n,times):
            right=mid
        else:
            left=mid
    
    return right

def solution(n, times):
    return bin_search(n,times)