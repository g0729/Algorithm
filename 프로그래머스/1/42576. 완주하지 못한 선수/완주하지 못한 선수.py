from collections import defaultdict

def solution(participant, completion):
    
    dic=defaultdict(int)

    for name in participant:
        dic[name]+=1
        
    for name in completion:
        dic[name]-=1
        
    for key,value in dic.items():
        if value == 1:
            return key