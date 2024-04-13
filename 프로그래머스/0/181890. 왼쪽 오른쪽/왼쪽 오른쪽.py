def solution(str_list):
    
    try:
        idx1=str_list.index('l')
    except:
        idx1=30
    try:
        idx2=str_list.index('r')
    except:
        idx2=30
    if idx1==30 and idx2==30:
        return []
    if idx1<idx2:
        return str_list[:idx1]
    else:
        return str_list[idx2+1:]