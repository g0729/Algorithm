import copy


def swipe(x, y, MAP, axis):
    n, m = len(MAP), len(MAP[0])
    if axis == 0:
        for i in range(m):
            MAP[x][i] = (MAP[x][i] + 1) % 2
    else:
        for i in range(n):
            MAP[i][y] = (MAP[i][y] + 1) % 2
    return MAP


def solution(beginning, target):
    answer = 1e9
    n, m = len(beginning), len(beginning[0])
    MAP = [[0] * m for _ in range(n)]

    for i in range(n):
        for j in range(m):
            if beginning[i][j] != target[i][j]:
                MAP[i][j] = 1

    for i in range(n):
        CMAP = copy.deepcopy(MAP)
        cnt = 0
        for j in range(m):
            if CMAP[i][j] == 1:
                CMAP = swipe(0, j, CMAP, 1)
                cnt += 1
        for j in range(n):
            if CMAP[j][0] == 1:
                CMAP = swipe(j, 0, CMAP, 0)
                cnt += 1
        answer = min(answer, cnt)

    for i in range(n):
        for j in range(m):
            if CMAP[i][j] == 1:
                return -1

    for i in range(m):
        CMAP = copy.deepcopy(MAP)
        cnt = 0
        for j in range(n):
            if CMAP[j][i] == 1:
                CMAP = swipe(j, i, CMAP, 0)
                cnt += 1
        for j in range(m):
            if (CMAP[0][j]) == 1:
                CMAP = swipe(0, j, CMAP, 1)
                cnt += 1
        answer = min(answer, cnt)

    return answer
