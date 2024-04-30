def solution(n, money):
    answer = 0
    dp=[0]*(n+1)
    dp[0]=1
    money.sort()
    
    for a in money:
        for i in range(a,n+1):
            dp[i]=(dp[i]+dp[i-a])%1000000007
    
    return dp[n]