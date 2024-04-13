def solution(arr):
    answer = 0
    for i in range(100):
        flag=True
        for idx in range(len(arr)):
            if arr[idx]%2==0 and arr[idx]>=50:
                flag=False
                arr[idx]=arr[idx]//2;
            elif arr[idx]%2==1 and arr[idx]<50:
                flag=False
                arr[idx]=arr[idx]*2+1
        
        if flag:
            return i