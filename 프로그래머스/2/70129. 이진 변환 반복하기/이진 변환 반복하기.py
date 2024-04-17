def solution(s):
    answer = [0,0]
    while s!='1':
        temp=0
        for c in s:
            if c=='1':
                temp+=1
        answer[0]+=1
        answer[1]+=len(s)-temp
        s=str(bin(temp)[2:])
                
    return answer