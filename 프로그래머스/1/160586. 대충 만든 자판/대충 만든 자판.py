def solution(keymap, targets):
    answer = []
    ma={}
    
    for keys in keymap:
        for idx,key in enumerate(keys):
            if key not in ma:
                ma[key]=idx+1
            else:
                ma[key]=min(ma[key],idx+1)
                
    for target in targets:
        flag=False;
        sum=0
        for c in target:
            if c not in ma:
                flag=True
                break
            else:
                sum+=ma[c]
        if flag:
            answer.append(-1)
        else:
            answer.append(sum)
    return answer