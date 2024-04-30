def solution(n, cores):
    answer = 0
    
    
    if n<=len(cores):
        return len(cores)
    def cal(target):
        return sum(target//core +1for core in cores)
    
    
    left,right=-1,int(1e9)
    
    while left+1<right:
        mid=(left+right)//2
        
        if cal(mid)>=n:
            right=mid
        else:
            left=mid
    
    idx=cal(right)-n
    
    if idx==0:
        for i in range(len(cores)-1,-1,-1):
            if right%cores[i]==0:
                return i+1
    else:
        for i in range(len(cores)-1,-1,-1):
            if right%cores[i]==0:
                if idx==0:
                    return i+1
                idx-=1
    
    return ans