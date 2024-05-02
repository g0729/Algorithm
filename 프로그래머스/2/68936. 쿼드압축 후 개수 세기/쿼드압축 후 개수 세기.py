def solution(arr):
    answer = [0,0]
    
    def divide(x,y,size):
        cnt=[0,0]
        
        for i in range(x,x+size):
            for j in range(y,y+size):
                cnt[arr[i][j]]+=1
        if max(cnt)==size**2:
            answer[0 if cnt[0]==size**2 else 1]+=1
        else:
            size//=2
            divide(x,y,size)
            divide(x+size,y,size)
            divide(x,y+size,size)
            divide(x+size,y+size,size)
    divide(0,0,len(arr))
    return answer