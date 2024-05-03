def solution(want, number, discount):
    ma={word:idx for idx,word in enumerate(want)}

    cnt=[0]*len(number)
    for i in range(10):
        try:
            cnt[ma[discount[i]]]+=1
        except:
            continue
    
    def check():
        for i in range(len(number)):
            if cnt[i]!=number[i]:
                return 0
        return 1

    answer=check()
    
    for i in range(len(discount)-10):
        try:
            cnt[ma[discount[i]]]-=1
        except:
            pass
        try:
            cnt[ma[discount[i+10]]]+=1
        except:
            pass
        answer+=check()
    return answer