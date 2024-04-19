def solution(elements):
    answer = 0
    se=set(elements)
    arr=[0]*(len(elements)+1)
    for i in range(1,len(elements)+1):
        arr[i]=arr[i-1]+elements[i-1]
    for length in range(1,len(elements)+1):
        for i in range(1,len(elements)+1):
            left,right=i,(i+length-1)%len(elements)+1
            if left<right:
                se.add(arr[right]-arr[left-1])
            else:
                se.add(arr[-1]-arr[left]+arr[right])
                
    return len(se)