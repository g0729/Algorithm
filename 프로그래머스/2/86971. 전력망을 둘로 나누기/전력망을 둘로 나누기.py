from collections import defaultdict,deque

def bfs(start,visited,edges):
    cnt=1
    q=deque()
    q.append(start)
    visited[start]=True
    
    while q:
        now=q.popleft()
        
        for nxt in edges[now]:
            if not visited[nxt]:
                visited[nxt]=True
                cnt+=1
                q.append(nxt)
                
    return cnt
def cal(n,edges):
    visited=[False]*(n+1)
    num1,num2=0,0
    for i in range(1,n+1):
        if not visited[i]:
            temp=bfs(i,visited,edges)
            if num1==0:
                num1=temp
            else:
                num2=temp
    
    return abs(num1-num2)
def solution(n, wires):
    answer=int(1e5)
    edges=defaultdict(list)
    for a,b in wires:
        edges[a].append(b)
        edges[b].append(a)
        
    for a,b in wires:
        edges[a].remove(b)
        edges[b].remove(a)
        answer=min(answer,cal(n,edges))
        edges[a].append(b)
        edges[b].append(a)
    
    return answer