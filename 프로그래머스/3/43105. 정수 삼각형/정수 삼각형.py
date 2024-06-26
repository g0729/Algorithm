def solution(triangle):
    answer = 0
    height=len(triangle)
    dp=[[0 for _ in range(height)] for _ in range(height)]
    dp[0][0]=triangle[0][0]
    
    for i in range(1,height):
        for j in range(len(triangle[i])):
            if j==0:
                dp[i][j]=dp[i-1][j]+triangle[i][j]
            elif j==len(triangle[i])-1:
                dp[i][j]=dp[i-1][j-1]+triangle[i][j]
            else:
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+triangle[i][j]
            
    return max(dp[height-1])