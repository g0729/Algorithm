def solution(matrix):
    n=len(matrix)
    
    dp=[[0 for _ in range(n+1)] for _ in range(n+1)]
    
    for diff in range(1,n):
        for left in range(0,n-diff):
            right=left+diff
            for mid in range(left,right):
                temp=dp[left][mid]+dp[mid+1][right]+matrix[left][0]*matrix[mid][1]*matrix[right][1]
                if dp[left][right]==0:
                    dp[left][right]=temp
                else:
                    dp[left][right]=min(dp[left][right],temp)
                
    return dp[0][n-1]
    