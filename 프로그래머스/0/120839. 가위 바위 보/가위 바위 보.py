def solution(rsp):
    ma={'2':'0','0':'5','5':'2'}
    return ''.join(ma[c] for c in rsp)