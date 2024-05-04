def solution(progresses, speeds):
    answer = []
    arr = [((100 - a + (b - 1)) // b) for a, b in zip(progresses, speeds)]
    day = arr[0]
    cnt = 1
    for a in arr[1:]:
        if a <= day:
            cnt += 1
        else:
            answer.append(cnt)
            day = a
            cnt = 1
    answer.append(cnt)
    return answer
