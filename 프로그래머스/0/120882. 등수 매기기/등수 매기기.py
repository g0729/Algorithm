def solution(score):
    temp=[[(score[i][0]+score[i][1])/2,i] for i in range(len(score))]
    temp.sort(key=lambda x : x[0],reverse=True)
    answer=[0]*len(score)
    
    
    answer[temp[0][1]]=1
    for i in range(1,len(temp)):
        if temp[i][0]==temp[i-1][0]:
            answer[temp[i][1]]=answer[temp[i-1][1]]
        else:
            answer[temp[i][1]]=i+1
    return answer
    