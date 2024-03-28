for _ in range(int(input())):
    input()
    n,m=map(int,input().split())
    cList=list(map(int,input().split()))
    eList=list(map(int,input().split()))

    cAvg=sum(cList)/n
    eAvg=sum(eList)/m

    res=0

    for i in range(n):
        if cList[i]<cAvg and cList[i]>eAvg:
            res+=1

    print(res)
