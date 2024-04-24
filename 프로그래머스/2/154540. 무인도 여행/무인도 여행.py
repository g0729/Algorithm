from collections import deque    

dx=[1,-1,0,0]
dy=[0,0,1,-1]
def solution(maps):
    answer = []
    n,m=len(maps),len(maps[0])
    visited=[[False for _ in range(m)] for _ in range(n)]
    def bfs(x,y):
        q=deque()
        q.append([x,y])
        visited[x][y]=True
        res=0
        while q:
            now=q.popleft()
            res+=int(maps[now[0]][now[1]])
            for i in range(4):
                nx=now[0]+dx[i]
                ny=now[1]+dy[i]
                
                if nx<0 or nx>=n or ny<0 or ny>=m:
                    continue
                if visited[nx][ny]:
                    continue
                if maps[nx][ny]=='X':
                    continue
                q.append([nx,ny])
                visited[nx][ny]=True
        return res
    
    for i in range(n):
        for j in range(m):
            if maps[i][j]!="X" and not visited[i][j]:
                answer.append(bfs(i,j))
    return sorted(answer) if answer else [-1]