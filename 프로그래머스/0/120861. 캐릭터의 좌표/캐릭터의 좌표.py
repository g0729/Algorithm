def solution(keyinput, board):
    move={"left":[-1,0],"right":[1,0],"up":[0,1],"down":[0,-1]}
    
    cur=[0,0]
    lim=[board[0]//2,board[1]//2]
    for s in keyinput:
        nxt=[cur[0]+move[s][0],cur[1] +move[s][1]]

        if -lim[0]<=nxt[0]<=lim[0] and -lim[1]<=nxt[1]<=lim[1]:
            cur=nxt
    return cur