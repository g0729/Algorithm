def solution(m, n, puddles):
    answer = 0
    MOD=1000000007
    dp=[[0 for _ in range(m)] for _ in range(n)]
    dp[0][0]=1
    for i in range(m):
        for j in range(n):
            if j==0 and i==0:
                continue
            if [i+1,j+1] in puddles:
                continue
            elif j==0:
                dp[j][i]=dp[j][i-1]
            elif i==0:
                dp[j][i]=dp[j-1][i]
            else:
                dp[j][i]=(dp[j-1][i]+dp[j][i-1])%MOD
    print(dp)            
    return dp[n-1][m-1]