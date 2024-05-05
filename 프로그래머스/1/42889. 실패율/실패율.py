def solution(N, stages):
    answer = []
    cnt=[0]*(N+2)
    for a in stages:
        cnt[a]+=1
    total=sum(cnt)
    for i in range(1,len(cnt)-1):
        try:
            answer.append([i,cnt[i]/total])
        except:
            answer.append([i,0])
        total-=cnt[i]
    answer.sort(key=lambda x : x[1],reverse=True)
    answer=[a for a,b in answer]
    return answer