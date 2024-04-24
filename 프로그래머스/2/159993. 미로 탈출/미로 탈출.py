from collections import deque
def solution(maps):

    q=deque()
    start=[0,0]
    exit=[0,0]
    n=len(maps)
    m=len(maps[0])
    for i in range(n):
        for j in range(m):
            if maps[i][j]=='S':
                start=[i,j]
            if maps[i][j]=='E':
                exit=[i,j]
    
    visited=[[[False,False] for _ in range(m)] for _ in range(n) ]
    q.append([start,0])
    visited[start[0]][start[1]][0]=True
    dx=[1,-1,0,0]
    dy=[0,0,1,-1]
    
    level=0
    while q:
        size=len(q)  
        while size:
            
            now,flag=q.popleft()
            if now==exit and flag==1:
                return level
            
            for i in range(4):
                nx=now[0]+dx[i]
                ny=now[1]+dy[i]
                
                if 0<=nx<n and 0<=ny<m:
                    if maps[nx][ny]=='X' or visited[nx][ny][flag]:
                        continue
                    if maps[nx][ny]=='L':
                        q.append([[nx,ny],1])
                        visited[nx][ny][1]=True
                    q.append([[nx,ny],flag])
                    visited[nx][ny][flag]=True
            size-=1
        level+=1
    return -1