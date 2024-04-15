def solution(board):
    answer = 0
    dx=[-1,-1,-1,0,0,1,1,1]
    dy=[-1,0,1,-1,1,-1,0,1]
    
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j]:
                continue
            flag=True
            for k in range(8):
                nx=i+dx[k]
                ny=j+dy[k]
                
                if nx<0 or nx>=len(board) or ny<0 or ny>=len(board[i]):
                    continue
                if board[nx][ny]:
                    flag=False
                    break
            if flag:
                answer+=1
                
    return answer