def solution(babbling):
    answer = 0
    for s in babbling:
        for idx,word in enumerate(['aya','ye','woo','ma']):
            s=s.replace(word,str(idx))
        flag=True
        for i in range(len(s)):
            if not s[i].isdigit():
                flag=False
                break
            if i!=0 and s[i]==s[i-1]:
                flag=False
                break
        if flag:
            answer+=1
    return answer