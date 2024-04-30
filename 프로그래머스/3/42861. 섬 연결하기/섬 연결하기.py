def solution(n, costs):
    answer = 0
    parent=[0]*n
    for i in range(n):
        parent[i]=i
        
    def find(x):
        if parent[x]==x:
            return x
        parent[x]=find(parent[x])
        return parent[x]
    def merge(a,b):
        a=find(a)
        b=find(b)
        if a==b:
            return
        parent[a]=b
    
    edges=[]
    
    for a,b,cost in costs:
        edges.append([cost,a,b])
    edges.sort()
    
    for cost,a,b in edges:
        if find(a)!=find(b):
            merge(a,b)
            answer+=cost
    return answer