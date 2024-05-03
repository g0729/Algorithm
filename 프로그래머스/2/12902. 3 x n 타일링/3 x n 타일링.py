def solution(n):
    if n%2:
        return 0
    dp=[0 for _ in range(n+1)]
    dp[0]=1
    dp[2]=3
    MOD=1000000007
    for i in range(4,n+1,2):
        temp=dp[i-2]*3
        for j in range(0,i-3,2):
            temp=(temp+dp[j]*2)%MOD
        dp[i]=temp
    
    return dp[n]