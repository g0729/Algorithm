def solution(survey, choices):
    answer = ''
    scores=[[0,0] for _ in range(4)]
    ma={'R':[0,0],'T':[0,1],
        'C':[1,0],'F':[1,1],
        'J':[2,0],'M':[2,1],
        'A':[3,0],'N':[3,1]}
    
    for i in range(len(choices)):
        choice=choices[i]
        if choice ==4:
            continue
        a,b=ma[survey[i][0]],ma[survey[i][1]]
        
        if choice<4:
            score=4-choice
            scores[a[0]][a[1]]+=score
        else:
            score=choice-4
            scores[b[0]][b[1]]+=score
    
    if scores[0][0]>=scores[0][1]:
        answer+='R'
    else:
        answer+='T'
    if scores[1][0]>=scores[1][1]:
        answer+='C'
    else:
        answer+='F'
    if scores[2][0]>=scores[2][1]:
        answer+='J'
    else:
        answer+='M'
    if scores[3][0]>=scores[3][1]:
        answer+='A'
    else:
        answer+='N'
    
    print(scores)
    
    return answer