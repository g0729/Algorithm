

def solution(word):
    words=[]
    arr=['A','E','I','O','U']
    def make_word(now,length,s):
        if now==length:
            words.append(s)
            return
        for c in arr:
            make_word(now+1,length,s+c)
    for i in range(1,6):
        make_word(0,i,'')
        
    words.sort()
    return words.index(word)+1
    