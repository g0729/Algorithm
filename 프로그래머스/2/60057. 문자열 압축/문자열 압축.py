def solution(s):
    answer = len(s)
    
    for length in range(1,len(s)//2+1):
        arr=[]
        for idx in range(0,len(s),length):
            arr.append(s[idx:idx+length])
        temp=length
        cnt=1
        for i in range(1,len(arr)):
            if arr[i]==arr[i-1]:
                cnt+=1   
                continue
            else:
                if cnt!=1:
                    temp+=len(str(cnt))
                    cnt=1
                temp+=len(arr[i])
        if cnt!=1:
            temp+=len(str(cnt))
        answer=min(answer,temp)
    return answer