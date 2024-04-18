def solution(k, ranges):
    answer = []
    arr=[k]
    while k!=1:
        k= k//2 if k%2==0 else k*3+1
        arr.append(k)
    for a,b in ranges:
        b= b if b>0 else len(arr)+b-1
        if b<a:
            answer.append(-1)
            continue
        res=0
        print(a,b)
        for i in range(a,b):
            res+=abs(arr[i+1]-arr[i])/2+min(arr[i+1],arr[i])
        answer.append(res)

    return answer