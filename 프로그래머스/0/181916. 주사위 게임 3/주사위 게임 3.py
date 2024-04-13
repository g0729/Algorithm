from collections import Counter
def solution(a, b, c, d):
    se=set([a,b,c,d])
    cnt=Counter([a,b,c,d])
    
    if len(se)==1:
        return a*1111
    elif len(se)==2:
        flag=True
        for num in cnt:
            if cnt[num]==2:
                flag=False
            
        if flag:
            temp=0
            for num in cnt:
                if cnt[num]==3:
                    temp+=num*10
                else:
                    temp+=num
            return temp**2
        else:
            temp=0
            temp2=0
            for idx,num in enumerate(cnt):
                temp+=num
                if idx%2:
                    temp2+=num
                else:
                    temp2-=num
            return temp*abs(temp2)
    elif len(se)==3:
        temp=1
        for num in cnt:
            if cnt[num]==1:
                temp*=num
        return temp
    else:
        return min([a,b,c,d])
