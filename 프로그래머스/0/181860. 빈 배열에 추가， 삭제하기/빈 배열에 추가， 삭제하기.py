def solution(arr, flag):
    answer = []
    for idx , a in enumerate(flag):
        if a:
            for _ in range(arr[idx]*2):
                answer.append(arr[idx])
        else:
            for _ in range(arr[idx]):
                answer.pop()
    return answer