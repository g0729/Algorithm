from collections import deque

def bfs(start,edge):
    q=deque()
    q.append(start)
    
    while q:
        now=q.popleft()
        
        if len(edge[now])==0:
            return 2
        if len(edge[now])==2:
            return 3
        
        for next_node in edge[now]:
            if next_node==start:
                return 1
            q.append(next_node)


def solution(edges):
    node_num=max([b for a in edges for b in a])
    
    edge=[[] for _ in range(node_num+1)]
    check=[0]*(node_num+1)
    for a,b in edges:
        edge[a].append(b)
        check[b]+=1
    
    start_node=0
    
    for i in range(1,len(check)):
        if check[i]==0 and len(edge[i])>=2:
            start_node=i
            break
    
    answer=[start_node,0,0,0]
    
    for next_node in edge[start_node]:
        answer[bfs(next_node,edge)]+=1
    
    return answer