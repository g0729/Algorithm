def solution(spell, dic):
    spell=''.join(sorted(spell))
    for s in dic:
        if ''.join(sorted(s))==spell:
            return 1
    
    return 2
    