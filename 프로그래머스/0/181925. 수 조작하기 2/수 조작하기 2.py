def solution(numLog):
    ma={1:'w',-1:'s',10:'d',-10:'a'}
    res=''
    for i in range(1,len(numLog)):
        res+=ma[numLog[i]-numLog[i-1]]
    return res