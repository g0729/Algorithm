def solution(common):
    diff=set([common[1]-common[0],common[2]-common[1]])
    
    if len(diff)==1:
        return common[-1]+(common[1]-common[0])
    else:
        return common[-1]*(common[1]//common[0])