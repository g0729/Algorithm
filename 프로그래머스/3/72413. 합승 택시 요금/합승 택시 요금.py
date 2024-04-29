def solution(n, s, a, b, fares):
    dist=[[0 for _ in range(n+1 )]for _ in range(n+1)]
    for c,d,e in fares:
        dist[c][d]=e
        dist[d][c]=e
    
    for i in range(1,n+1):
        for j in range(1,n+1):
            if i==j:
                dist[i][j]=0
            elif dist[i][j]==0:
                dist[i][j]=int(1e9)
                
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
    answer=int(1e9)
    for i in range(1,n+1):
        answer=min(answer,dist[s][i]+dist[i][a]+dist[i][b])
    return answer