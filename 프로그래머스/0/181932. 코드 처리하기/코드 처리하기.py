def solution(code):
    answer = ''
    mode=0
    for idx, c in enumerate(code):
        if mode==0:
            if c!='1' and idx%2==0:
                answer+=c
            elif c=='1':
                mode=(mode+1)%2
        else:
            if c!='1' and idx%2==1:
                answer+=c
            elif c=='1':
                mode=(mode+1)%2
        
    return answer if answer else "EMPTY"