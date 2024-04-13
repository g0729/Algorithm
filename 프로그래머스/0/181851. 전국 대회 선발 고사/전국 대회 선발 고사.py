def solution(rank, attendance):
    answer = 0
    temp=[]
    for i in range(len(rank)):
        if attendance[i]:
            temp.append([rank[i],i])
    temp2=sorted(temp)

    return temp2[0][1]*10000+temp2[1][1]*100+temp2[2][1]