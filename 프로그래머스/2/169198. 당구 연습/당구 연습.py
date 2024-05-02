def dis(x1, y1, x2, y2):
    return (y2 - y1) ** 2 + (x2 - x1) ** 2


def cal(m, n, startX, startY, ball):

    candidate = []
    if ball[1] != startY:
        candidate.append(dis(ball[0], ball[1], -startX, startY))
    elif ball[0] > startX:
        candidate.append(dis(ball[0], ball[1], -startX, startY))

    if ball[0] != startX:
        candidate.append(dis(ball[0], ball[1], startX, -startY))
    elif ball[1] > startY:
        candidate.append(dis(ball[0], ball[1], startX, -startY))

    if ball[1] != startY:
        candidate.append(dis(ball[0], ball[1], 2 * m - startX, startY))
    elif ball[0] < startX:
        candidate.append(dis(ball[0], ball[1], 2 * m - startX, startY))

    if ball[0] != startX:
        candidate.append(dis(ball[0], ball[1], startX, 2 * n - startY))
    elif ball[1] < startY:
        candidate.append(dis(ball[0], ball[1], startX, 2 * n - startY))


    
    return min(candidate)


def solution(m, n, startX, startY, balls):
    answer = []
    for ball in balls:
        answer.append(cal(m, n, startX, startY, ball))

    return answer
