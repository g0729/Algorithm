for _ in range(int(input())):
    m,n=map(int,input().split())

    arr=[list(map(int ,input().split())) for _ in range(n)]

    res={}
    for i in range(m):
        temp=1
        for j in range(n):
            temp*=arr[j][i]
        res[temp]=i+1
    print(res[max(res)])