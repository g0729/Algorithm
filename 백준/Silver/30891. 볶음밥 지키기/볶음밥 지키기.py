from math import sqrt


def distance(x1, y1, x2, y2):
    return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


def cal(x, y):
    res = 0
    for rice in rices:
        if distance(x, y, rice[0], rice[1]) <= r:
            res += 1
    return res


n, r = map(int, input().split())
rices = [list(map(int, input().split())) for _ in range(n)]
answer = [0, 0]
answer_cnt = 0
for x in range(-100, 100):
    for y in range(-100, 100):
        temp = cal(x, y)
        if answer_cnt < temp:
            answer_cnt = temp
            answer = [x, y]

print(answer[0], answer[1])
